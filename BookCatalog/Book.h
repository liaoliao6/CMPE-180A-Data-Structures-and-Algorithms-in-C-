#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <vector>

using namespace std;

class Book  //book class, contain all info in one book and related operators
{
public:

    Book();

    Book(string isbn, string last, string first, string title, string category);

    ~Book();

    friend ostream & operator << (ostream & outs, const Book & book1);

    friend istream & operator >> (istream & ins, Book & book1);

    string ISBN;
    string authorLast;
    string authorFirst;
    string Title;
    string bookCategory;

private:

};

class BookCollection    //bookcollection class
{
public:

    BookCollection();

    ~BookCollection();

    void InsertBook(Book newBook, int index);

    void RemoveBook(int index);

    int SearchBookISBN(string ISBN, int low, int high);

    void SearchBookAuthor(string Author, int number);

    void SearchBookCategory(string Category, int number);

    vector<Book> collection;

private:

};

#endif /* EMPLOYEE_H_ */