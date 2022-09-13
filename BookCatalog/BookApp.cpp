#include "Book.h"
#include <fstream>
#include <iostream>
#include <sstream>
//#include <string>
//#include <vector>

/***** Author: Jingjing Bu *****/

using namespace std;


/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
//int find(const string isbn, const vector<Book>& catalog);

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
    // Open the input file.
    ifstream input; //input stream
    int index = 0;  //vector index
    int number = 0; //vector number
    char command;   //commands in the .in file

    input.open(INPUT_FILE_NAME);
    if (input.fail()) {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    BookCollection newCollection;  // book catalog


    while (!input.eof())
    {
        string line;
        Book newBook;   //book object
        input >> command;   //read command
        getline(input, line);   //read one line
        line.erase(0,1);    //erase the first space in line

        if (command == '+') //input command +
        {
            cout << endl << command << " ";
            istringstream iss (line);   //convert string to input stream
            iss >> newBook; //input string into book object
            newCollection.InsertBook(newBook, number);  //insert the book to the last position of the collection
            number += 1;    //book number + 1

            int i = 0;

            for( ; newBook.ISBN.substr(4,10) > newCollection.collection[i].ISBN.substr(4,10); ) //find the right position
            {
                i++;
                index = i;
            }

            newCollection.InsertBook(newBook, index); //insert the book to the right position
            newCollection.RemoveBook(number + 1);   //remove the new book in the last position

            cout << "Inserted at index " << index << ": ";  //output
            cout << newBook << endl;
            if (number != 1 && number != 2)
                if (newBook.ISBN.substr(4,10) == newCollection.collection[index + 1].ISBN.substr(4,10))
                {
                    cout << "*** Duplicate ISDN ***" << endl;   //if input duplicate book
                    newCollection.RemoveBook(index);
                    number -= 1;
                }
        }
        else if (command == '?')    //input command ?
        {
            cout << endl << command << " ";
            istringstream iss (line);
            string keywords = line;
            string searchWords;
            iss >> searchWords;

            if (keywords == "\0")   //if only ?
            {
                cout << "All books in the catalog:" << endl;
                for(int i =0; i < number; i++)
                    cout << newCollection.collection[i] << endl;    //output all books in collection
                command = ' ';
            }
            else if (searchWords.at(0) == 'i')  //if input ?isbn
            {
                string searchisbn = searchWords.substr(9, 10);  //isbn
                int searchIndex = newCollection.SearchBookISBN(searchisbn, 0, number - 1);  //find the right book position
                cout << "Book with ISBN " << searchWords.substr(5, 14) << ":" << endl;
                if (searchIndex != -1)
                {
                    cout << newCollection.collection[searchIndex] << endl;  //could not find right book
                }
            }
            else if (searchWords.at(0) == 'a')  //if ?author
            {
                string searchauthor = searchWords.substr(7, 3);
                string author;
                if (searchauthor.at(0) == 'H')  //find the right author name
                    author = "Horstmann";
                else if (searchauthor.at(0) == 'K')
                    author = "King";
                else author = searchauthor;

                cout << "Books by author " << author << ":" << endl;
                newCollection.SearchBookAuthor(author, number); //search and output books
            }
            else if(searchWords.at(0) == 'c')   //if input ?category
            {
                string searchCategory = searchWords.substr(9, 7);
                string category;
                if (searchCategory.at(0) == 't')    //find the right category name
                    category = "technical";
                else category = searchCategory;

                cout << "Books in category " << category << ":" << endl;
                newCollection.SearchBookCategory(category, number); //find all books in the category and then output
            }
            else ;

        }
        else if (command == '-')    //if input command -
        {
            cout << endl << command << " " << "Removed ";
            string ISDN = line;
            int rmindex = 0;
            for (; newCollection.collection[rmindex].ISBN != ISDN && rmindex < number + 1; rmindex++);  //find book index
            if (rmindex < number)
            {
                cout << newCollection.collection[rmindex] << endl;
                newCollection.RemoveBook(rmindex);  //remove book
                number -= 1;
            }
            else    //if we could not find book to be removed
            {
                Book invalidBook(ISDN, "", "", "", "none" );
                cout << invalidBook << endl;
                cout << "*** Book not found ***" << endl;
            }



        }
        else if (command == ' ')    //reset command, avoid reading space in the last line of command.in file
        {

        }
        else    //invalid commands
        {
            cout << endl << command << " ";
            cout << "*** Invalid command ***" << endl;
        }



    }
    input.close();  //close file
    return 0;
}