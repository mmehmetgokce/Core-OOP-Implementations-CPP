#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Complex {
    double real, imag;

    // + operatörünün aşırı yüklenmesi
    Complex operator+(const Complex& other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
};

struct Vector3D {
    double x, y, z;

    // * operatörünün aşırı yüklenmesi (scalar ile çarpma)
    Vector3D operator*(double scalar) {
        Vector3D result;
        result.x = this->x * scalar;
        result.y = this->y * scalar;
        result.z = this->z * scalar;
        return result;
    }
};

struct Fraction {
    double pay, payda;

    // == operatörünün aşırı yüklenmesi
    bool operator==(const Fraction& other) {
        return (this->pay * other.payda == this->payda * other.pay);
    }
};

struct Counter {
    int value;

    // Kurucu fonksiyon
    Counter(int v = 0) : value(v) {}

    // ++ operatörünün aşırı yüklenmesi (prefix)
    Counter& operator++() {
        this->value += 2; // İkişer artırma
        return *this;
    }

    // ++ operatörünün aşırı yüklenmesi (postfix)
    Counter operator++(int) {
        Counter temp = *this;
        this->value += 2; // İkişer artırma
        return temp;
    }

    // -- operatörünün aşırı yüklenmesi (prefix)
    Counter& operator--() {
        this->value -= 2; // İkişer azaltma
        return *this;
    }

    // -- operatörünün aşırı yüklenmesi (postfix)
    Counter operator--(int) {
        Counter temp = *this;
        this->value -= 2; // İkişer azaltma
        return temp;
    }
};

// max fonksiyonlarının deklarasyonları
int max(int a, int b);
double max(double a, double b);
char max(char a, char b);

// print fonksiyonlarının deklarasyonları
void print(int value);
void print(double value);
void print(string value);
void print(char value);

// calculate fonksiyonlarının deklerasyonları
int calculate(int a, int b);
int calculate(int a, int b, int c);
int calculate(int a, int b, char operation);

int main() {

    // 1. Karmaşık Sayı Toplama Testleri
    for (int i = 0; i < 10; ++i) {
        Complex a = { i, i + 1 };
        Complex b = { i + 2, i + 3 };
        Complex result = a + b;
        if (result.real == a.real + b.real && result.imag == a.imag + b.imag) {
            cout << "Complex test success." << endl;
        }
        else {
            cout << "Complex test FAIL." << endl;
        }
    }

    // 2. Vektör Çarpımı Testleri
    for (int i = 0; i < 10; ++i) {
        Vector3D v = { i, i + 1, i + 2 };
        double scalar = i * 1.5;
        Vector3D result = v * scalar;
        if (result.x == v.x * scalar && result.y == v.y * scalar && result.z == v.z * scalar) {
            cout << "Vector test success." << endl;
        }
        else {
            cout << "Vector test FAIL." << endl;
        }
    }

    // 3. Kesitli Sayı Karşılaştırma Testleri
    for (double i = 1; i <= 10; ++i) {
        Fraction f1 = { i, 2 * i };
        Fraction f2 = { i / 2, i };
        if ((f1 == f2) == true) {
            cout << "Fraction test success." << endl;
        }
        else {
            cout << "Fraction test FAIL." << endl;
        }
    }

    // 4. max Fonksiyonu Testleri
    cout << endl << "Max tests" << endl;
    if (max(3, 5) == 5) cout << "Max test 1 success." << endl;
    if (max(7.2, 7.1) == 7.2) cout << "Max test 2 success." << endl;
    if (max('a', 'b') == 'b') cout << "Max test 3 success." << endl;

    // 5. print Fonksiyonu Testleri
    cout << endl << "Print tests" << endl;
    print(10);
    print(3.14);
    print("Hello");
    print('A');


    // 6. Sayaç Testi

    Counter counter(0);

    // Test 1: Prefix '++' operatörü
    ++counter;
    if (counter.value == 2) {
        std::cout << "Test 1 Success: ++counter, value = " << counter.value << std::endl;
    }
    else {
        std::cout << "Test 1 FAIL: ++counter, value = " << counter.value << std::endl;
    }

    // Test 2: Postfix '++' operatörü
    counter++;
    if (counter.value == 4) {
        std::cout << "Test 2 Success: counter++, value = " << counter.value << std::endl;
    }
    else {
        std::cout << "Test 2 FAIL: counter++, value = " << counter.value << std::endl;
    }

    // Test 3: Prefix '--' operatörü
    --counter;
    if (counter.value == 2) {
        std::cout << "Test 3 Success: --counter, value = " << counter.value << std::endl;
    }
    else {
        std::cout << "Test 3 FAIL: --counter, value = " << counter.value << std::endl;
    }

    // Test 4: Postfix '--' operatörü
    counter--;
    if (counter.value == 0) {
        std::cout << "Test 4 Success: counter--, value = " << counter.value << std::endl;
    }
    else {
        std::cout << "Test 4 FAIL: counter--, value = " << counter.value << std::endl;
    }

    // 7. calculate Fonksiyonu Testleri
    // Toplama işlemi testleri
    for (int i = 0; i < 10; ++i) {
        int a = i;
        int b = i + 1;
        int result = calculate(a, b);
        int expected = a + b;
        if (result == expected) {
            cout << "Sum test success: " << a << " + " << b << " = " << result << endl;
        }
        else {
            cout << "Sum test FAIL: " << a << " + " << b << " = " << result << " (expected: " << expected << ")" << endl;
        }
    }

    // Çarpma işlemi testleri
    for (int i = 1; i <= 10; ++i) {
        int a = i;
        int b = i + 1;
        int c = i + 2;
        int result = calculate(a, b, c);
        int expected = a * b * c;
        if (result == expected) {
            cout << "Multiply test success: " << a << " * " << b << " * " << c << " = " << result << endl;
        }
        else {
            cout << "Multiply test FAIL: " << a << " * " << b << " * " << c << " = " << result << " (expected: " << expected << ")" << endl;
        }
    }

    // Çıkarma işlemi testleri
    for (int i = 0; i < 10; ++i) {
        int a = i + 10;
        int b = i;
        int result = calculate(a, b, '-');
        int expected = a - b;
        if (result == expected) {
            cout << "Subtract test success: " << a << " - " << b << " = " << result << endl;
        }
        else {
            cout << "Subtract test FAIL: " << a << " - " << b << " = " << result << " (expected: " << expected << ")" << endl;
        }
    }

    return 0;
}

// int için max fonksiyonu
int max(int a, int b) {
    return (a > b) ? a : b;
}

// double için max fonksiyonu
double max(double a, double b) {
    return (a > b) ? a : b;
}

// char için max fonksiyonu
char max(char a, char b) {
    return (a > b) ? a : b;
}

// int için print fonksiyonu
void print(int value) {
    cout << "Int: " << value << endl;
}

// double için print fonksiyonu
void print(double value) {
    cout << "Double: " << value << endl;
}

// string için print fonksiyonu
void print(string value) {
    cout << "String: " << value << endl;
}

// char için print fonksiyonu
void print(char value) {
    cout << "Char: " << value << "\n\n";
}

// İki tamsayıyı toplayan calculate fonksiyonu
int calculate(int a, int b) {
    return a + b;
}

// Üç tamsayıyı çarpan calculate fonksiyonu
int calculate(int a, int b, int c) {
    return a * b * c;
}

// Bir tamsayıdan diğerini çıkaran calculate fonksiyonu ('-' işaretiyle)
int calculate(int a, int b, char operation) {
    if (operation == '-') {
        return a - b;
    }
    return 0;  // Varsayılan durum
}
