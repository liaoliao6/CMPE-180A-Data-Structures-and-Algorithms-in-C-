#include "WordMap.h"

int WordMap :: get_count(const string text) const
{
    map<string, Word>::const_iterator itm = begin();
    while(itm != end())
    {
        if (itm->second.get_text() == text) //Compare text in the map
            return itm->second.get_count();
    }
    return 0;   //If could not find text in the map
}

void WordMap :: insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();  //Start timer

    map<string, Word>::iterator itm = search(text); //Search for the right pair in the map

    if (itm != end())
        itm->second.increment_count();  //Increase the count if find the pair
    else
    {
        Word *newWord = new Word(text);
        map<string, Word> :: insert (pair <string, Word>(text, *newWord));  //if can not find it, insert using text sequence, so do not need sort.
    }

    steady_clock::time_point end_time = steady_clock::now();    //Stop timer
    increment_elapsed_time(start_time, end_time);   //Calculate elapsed time

}

map<string, Word>::iterator WordMap :: search(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();

    map<string, Word>::iterator itm = begin();

    while(itm != end()) //Linear search
    {
        if (itm->second.get_text() == text)
        {
            steady_clock::time_point end_time = steady_clock::now();
            increment_elapsed_time(start_time, end_time);
            return itm;
        }   //Find the pair

        else itm++;
    }
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time, end_time);
    return end();   //Can not find the pair


}