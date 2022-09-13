#include "WordList.h"
#include <algorithm>

int WordList :: get_count(const string text)
{
    list<Word>::iterator itl = search(text);    //Use search to find the right Word

   if (itl != end())
       return itl ->get_count();
   else
       return 0;    //If no Word is found in the list, return 0
}

void WordList :: insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();  //Start timer

    list<Word>::iterator itl = begin();

    if (size() == 0)
    {
       Word *newWord = new Word(text);
       list<Word>::insert(itl, *newWord);
    }
    else
    {
        while ((itl != end()) && (itl->get_text() < text))
            itl++;

        if ((itl != end()) && (itl->get_text() == text)) //The text is in the list
        {
            itl->increment_count();
        }
        else //Can not find it in the list
        {
            Word *newWord = new Word(text);
            list<Word>:: insert(itl, *newWord);

        }
    }


    steady_clock::time_point end_time = steady_clock::now();    //Stop timer

    increment_elapsed_time(start_time, end_time);   //Calculate elapsed time

}

list<Word>::iterator WordList :: search(const string text)
{
    //sort(Comparelist);  //Sort list based on the text

    steady_clock::time_point start_time = steady_clock::now();  //Start timer

    list<Word>::iterator ser = find(text);  //Search for the text

    steady_clock::time_point end_time = steady_clock::now();    //Stop timer

    increment_elapsed_time(start_time, end_time);   //Calculate elapsed time

    return ser;

}



list<Word>::iterator WordList :: find(const string text)
{
    list<Word>::iterator itls = begin();

    while (itls != end())   //Linear search
    {
        if (itls->get_text() == text)
        {
            return itls;
        }
        else itls++;
    }
    return end();
}