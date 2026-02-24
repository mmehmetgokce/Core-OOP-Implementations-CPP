#include <iostream>
#include <iomanip>
#include <algorithm>
#include <time.h>

template<class T>
T GenerateRandomNumber(int lowerBound, int upperBound, double scaler = 1)
{
    lowerBound *= scaler;
    upperBound *= scaler;

    T randomData = lowerBound + rand() % (upperBound - lowerBound + 1);
    randomData /= scaler;

    return randomData;
}

template <typename T>
class ArrayHelper {
public:
    ArrayHelper() {}
    ~ArrayHelper() {}

    // Display Function
    void Display(const T* array, int size, int numberOfElementsInOneLine, int oneElementLength) const {
        std::cout << std::fixed << std::setprecision(2);
        for (int i = 0; i < size; ++i) {
            std::cout << std::setw(oneElementLength) << array[i];
            if ((i + 1) % numberOfElementsInOneLine == 0 || i == size - 1)
                std::cout << std::endl;
        }
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(4);
    }

    int MaxIndex(const T* array, int size) const {
        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (array[i] > array[maxIndex])
                maxIndex = i;
        }
        return maxIndex;
    }

    int MinIndex(const T* array, int size) const {
        int minIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (array[i] < array[minIndex])
                minIndex = i;
        }
        return minIndex;
    }

    T* Merge(const T* firstArray, int firstArraySize, const T* secondArray, int secondArraySize) const {
        T* mergedArray = new T[firstArraySize + secondArraySize];
        std::copy(firstArray, firstArray + firstArraySize, mergedArray);
        std::copy(secondArray, secondArray + secondArraySize, mergedArray + firstArraySize);
        return mergedArray;
    }

    void Sort(T* array, int size) const {
        std::sort(array, array + size);
    }

    void Swap(T& operand1, T& operand2) const {
        T temp = operand1;
        operand1 = operand2;
        operand2 = temp;
    }
};

int main()
{
    srand(time(NULL));
    int minIndex, maxIndex;
    ArrayHelper<int> IntegerArrayHelper;
    int IntegerArray1[10];
    for (size_t i = 0; i < 10; i++)
    {
        IntegerArray1[i] = GenerateRandomNumber<int>(-50, 50, 1);
    }
    IntegerArrayHelper.Display(IntegerArray1, 10, 5, 4);
    IntegerArrayHelper.Sort(IntegerArray1, 10);
    IntegerArrayHelper.Display(IntegerArray1, 10, 5, 4);
    minIndex = IntegerArrayHelper.MinIndex(IntegerArray1, 10);
    maxIndex = IntegerArrayHelper.MaxIndex(IntegerArray1, 10);
    std::cout << "Min : " << IntegerArray1[minIndex] << std::endl;
    std::cout << "Max : " << IntegerArray1[maxIndex] << std::endl;
    std::cout << "\n";

    int IntegerArray2[5];
    for (size_t i = 0; i < 5; i++)
    {
        IntegerArray2[i] = GenerateRandomNumber<int>(-50, 50, 1);
    }
    IntegerArrayHelper.Display(IntegerArray2, 5, 5, 4);
    int* newArray = IntegerArrayHelper.Merge(IntegerArray1, 10, IntegerArray2, 5);
    IntegerArrayHelper.Display(newArray, 15, 5, 4);
    std::cout << "\n";
    std::cout << "\n";

    ArrayHelper<double> doubleHelper;
    double doubleArray1[10];
    for (size_t i = 0; i < 10; i++) {
        doubleArray1[i] = GenerateRandomNumber<double>(-50.0, 50.0, 1.1);
    }
    doubleHelper.Display(doubleArray1, 10, 5, 8);
    doubleHelper.Sort(doubleArray1, 10);
    doubleHelper.Display(doubleArray1, 10, 5, 8);
    minIndex = doubleHelper.MinIndex(doubleArray1, 10);
    maxIndex = doubleHelper.MaxIndex(doubleArray1, 10);
    std::cout << "Min: " << doubleArray1[minIndex] << std::endl;
    std::cout << "Max: " << doubleArray1[maxIndex] << std::endl;
    std::cout << "\n";

    double doubleArray2[5];
    for (size_t i = 0; i < 5; i++) {
        doubleArray2[i] = GenerateRandomNumber<double>(-50.0, 50.0, 1.1);
    }
    doubleHelper.Display(doubleArray2, 5, 5, 8);
    double* mergedDoubleArray = doubleHelper.Merge(doubleArray1, 10, doubleArray2, 5);
    doubleHelper.Display(mergedDoubleArray, 15, 5, 8);
    delete[] mergedDoubleArray;
    std::cout << "\n";
    std::cout << "\n";

    ArrayHelper<char> charHelper;
    char charArray1[10] = { 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
    charHelper.Display(charArray1, 10, 5, 2);
    charHelper.Sort(charArray1, 10);
    charHelper.Display(charArray1, 10, 5, 2);
    minIndex = charHelper.MinIndex(charArray1, 10);
    maxIndex = charHelper.MaxIndex(charArray1, 10);
    std::cout << "Min: " << charArray1[minIndex] << std::endl;
    std::cout << "Max: " << charArray1[maxIndex] << std::endl;
    std::cout << "\n";

    char charArray2[5] = { 'o', 'n', 'm', 'l', 'k' };
    charHelper.Display(charArray2, 5, 5, 2);
    char* mergedCharArray = charHelper.Merge(charArray1, 10, charArray2, 5);
    charHelper.Display(mergedCharArray, 15, 5, 2);
    delete[] mergedCharArray;

    return 0;
}