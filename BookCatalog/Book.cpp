#include "Book.h"
#include <ostream>
#include <iostream>


using namespace std;

Book::Book()
{

}

Book::Book(string isbn, string last, string first, string title, string category)   //constructor
{
    ISBN = isbn;
    authorLast = last;
    authorFirst = first;
    Title = title;
    bookCategory = category;
}

Book::~Book()
{

}

ostream &operator << (ostream & outs, const Book & book1)   //overload <<
{
    outs << "Book{ISBN=" << book1.ISBN << ", last=" << book1.authorLast << ", first=" <<book1.authorFirst << ", title=" << book1.Title << ", category=" <<book1.bookCategory <<"}" ;
    return outs;
}

istream &operator >> (istream & ins, Book & book1)  //overload >>
{
    getline(ins, book1.ISBN, ',');
    getline(ins, book1.authorLast, ',');
    getline(ins, book1.authorFirst, ',');
    getline(ins, book1.Title, ',');
    getline(ins, book1.bookCategory, ',');
    return ins;
}

BookCollection::BookCollection()    //constructor
{
    collection.reserve(10); //reserve vector size
}

BookCollection::~BookCollection()
{

}


void BookCollection::InsertBook(Book newBook, int index)    //insert book into collection
{
    collection.insert (collection.begin() + index, newBook);
}

void BookCollection::RemoveBook(int index)  //remove book from collection
{
    collection.erase (collection.begin() + index);
}

int BookCollection::SearchBookISBN(string ISBN, int low, int high)  //search book ISBN, return index
{
    while (low < high)  //binary search
    {
        int mid = (low + high) / 2;
        if (collection[mid].ISBN.substr(4, 10) == ISBN )
            return mid;
        if (collection[mid].ISBN.substr(4, 10) > ISBN)
            high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

void BookCollection::SearchBookAuthor(string Author, int number)    //search for book with Author
{
    for (int i =0; i< number; i++ )
    {
        if (collection[i].authorLast == Author)
            cout << collection[i] << endl;
    }

}

void BookCollection::SearchBookCategory(string Category, int number)    //search books in the Category
{
    for (int i =0; i< number; i++ )
    {
        if (collection[i].bookCategory == Category)
            cout << collection[i] << endl;
    }
}