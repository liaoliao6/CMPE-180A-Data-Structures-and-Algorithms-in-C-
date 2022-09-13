/* Author: JIngjing Bu */

#include "WordVector.h"
#include <algorithm>


int WordVector :: get_count(const string text) const
{
    for(int i = 0; i < size(); i++)
    {
        if ((begin() + i)->get_text() == text)  //Compare the text in the vector with target
            return (begin() + i)->get_count();
    }
    return 0;
}


void WordVector :: insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();  //Start timer

    vector<Word>::iterator itv = begin();

    if (size() == 0)
    {
        Word *newWord = new Word(text);
        vector<Word>::insert(itv, *newWord);
    }
    else
    {
        while ((itv != end()) && (itv->get_text() < text))
            itv++;
        if (itv->get_text() == text) //The text is in the vector
        {
            itv->increment_count();
        }
        else //Can not find it in the vector
        {
            Word *newWord = new Word(text);
            vector<Word>:: insert(itv, *newWord);
        }
    }

    steady_clock::time_point end_time = steady_clock::now();    //Stop timer

    increment_elapsed_time(start_time, end_time);   //Calculate used time

}

vector<Word>::iterator WordVector :: search(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();  //Start timer

    int high = size() - 1;  //Last element index
    int low = 0;
    vector<Word>::iterator itvs = begin();

    int position = find (text, low, high);  //Binary sort

    steady_clock::time_point end_time = steady_clock::now();    //Stop timer

    increment_elapsed_time(start_time, end_time);   //Calculate elapsed time

    if (position == -1) //Can not find, return end + 1 of the vector
        return end();
    else
    return itvs + position; //return the position



}

int WordVector :: find(const string text, int low, int high) const  //Binary sort
{

    string key = text;  //find key

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<Word>::const_iterator itvs = begin();
        if(key == (itvs + mid)->get_text()) //if find the element == key
        {
            return mid;
        }
        if(key < (itvs + mid)->get_text())
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;  //If no key in the vector
}

