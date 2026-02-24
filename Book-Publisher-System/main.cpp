#include <iostream>
#include <string>

using namespace std;

class Publisher {
private:
    string name;
    string address;

public:
    Publisher(string name, string address) {
        this->name = name;
        this->address = address;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getAddress() {
        return address;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void printPublisherInfo() {
        cout << "Publisher Name: " << name << endl;
        cout << "Publisher Address: " << address << endl;
    }
};

class Author {
private:
    string name;
    int birthYear;
    string nationality;
    int deathYear;

public:
    Author(string name, int birthYear, int deathYear, string nationality) {
        this->name = name;
        this->birthYear = birthYear;
        this->nationality = nationality;
        this->deathYear = deathYear;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    int getBirthYear() {
        return birthYear;
    }

    void setBirthYear(int birthYear) {
        this->birthYear = birthYear;
    }

    string getNationality() {
        return nationality;
    }

    void setNationality(string nationality) {
        this->nationality = nationality;
    }

    int getDeathYear() {
        return deathYear;
    }

    void setDeathYear(int deathYear) {
        this->deathYear = deathYear;
    }

    void printAuthorInfo() {
        cout << "Author Name: " << name << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Death Year: " << deathYear << endl;
    }
};

class Book {
private:
    string title;
    int page;
    Author author;
    Publisher publisher;
    int publicationYear;

public:
    Book(string title, int page, int publicationYear, Author author, Publisher publisher)
        : author(author), publisher(publisher) {
        this->title = title;
        this->page = page;
        this->publicationYear = publicationYear;
    }

    string getTitle() {
        return title;
    }

    void setTitle(string title) {
        this->title = title;
    }

    int getPage() {
        return page;
    }

    void setPage(int page) {
        this->page = page;
    }

    Author getAuthor() {
        return author;
    }

    void setAuthor(Author author) {
        this->author = author;
    }

    Publisher getPublisher() {
        return publisher;
    }

    void setPublisher(Publisher publisher) {
        this->publisher = publisher;
    }

    int getPublicationYear() {
        return publicationYear;
    }

    void setPublicationYear(int publicationYear) {
        this->publicationYear = publicationYear;
    }

    void printBookInfo() {
        cout << "Book Title: " << title << endl;
        cout << "Page Count: " << page << endl;
        author.printAuthorInfo();
        publisher.printPublisherInfo();
        cout << "Publication Year: " << publicationYear << endl;
    }
};

int authorAgeAtPublication(Author author, Book book) {
    return book.getPublicationYear() - author.getBirthYear();
}

double calculatePrintingCost(Book book, double costPerPage) {
    return book.getPage() * costPerPage;
}

int main()
{
    Author author("Halil Inalcik", 1916, 2016, "Turkish");
    Publisher publisher("Eren Yayincilik", "Istanbul, Turkiye");
    Book book("Balkanlar", 299, 1993, author, publisher);

    cout << "AUTHOR & BOOK INFO TEST" << endl;
    cout << "-----------------------------" << endl;
    author.printAuthorInfo();
    cout << "-----------------------------" << endl;
    book.printBookInfo();
    cout << "-----------------------------" << endl << endl;

    cout << "FUNCTION TEST" << std::endl;
    cout << "-----------------------------" << endl;
    cout << "Author age at publication: " << authorAgeAtPublication(author, book) << endl;
    cout << "Printing cost:  " << calculatePrintingCost(book, 0.1) << endl;
    cout << "-----------------------------" << endl << endl;

    return 0;
}