#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

/***** Complete this file. *****/

bool SortedList::check() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (size() == 0) return true;

    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

void SortedList :: prepend(const long value)
{
    Node newNode(value);
    push_front(newNode);
}

void SortedList :: append(const long value)
{
    Node newNode(value);
    push_back(newNode);
}

void SortedList :: insert(const long value)
{
    Node newNode(value);
    list<Node>::const_iterator it = begin();
    while ((it != end()) && (it->get_value() <= value))
    {
        it++;
    }
    list<Node>::insert (it,newNode);
}

void SortedList :: remove(const int index)
{
    list<Node>::const_iterator it = begin();
    std::advance (it,index);
    erase(it);
}

void SortedList :: reverse()
{
    list<Node>::const_iterator be = begin();
    list<Node>::const_iterator it = begin();
    list<Node>::const_iterator prev = it;

    std::advance(it, 1);
     // Ensure that each node is less than or equal to the previous node.
    while (it != end()) {
        prepend(it->get_value());
        prev = it;
        std::advance(it, 1);
        erase(prev);
    }

}

Node SortedList :: operator[](const int index)
{
    list<Node>::const_iterator it= begin();
    std::advance(it, index);
    Node newNode(it->get_value());
    return newNode;
}