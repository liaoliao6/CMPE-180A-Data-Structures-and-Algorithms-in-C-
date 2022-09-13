#include <iostream>
#include <iterator>
#include <list>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}



bool SortedVector::check() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (size() == 0) return true;

    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == end();  // Good if reached the end.
}

void SortedVector :: prepend(const long value)
{
    Node newNode(value);
    vector<Node>::const_iterator it = begin();
    vector<Node>::insert (it,newNode);
}

void SortedVector :: append(const long value)
{
    Node newNode(value);
    push_back(value);
}

void SortedVector :: insert(const long value)
{
    Node newNode(value);
    vector<Node>::const_iterator it = begin();
    while ((it != end()) && (it->get_value() <= value))
    {
        it++;
    }
    vector<Node>::insert (it,newNode);
}

void SortedVector :: remove(const int index)
{
    vector<Node>::const_iterator it = begin();
    it = it + index;
    erase(it);
}

void SortedVector :: reverse()
{
    vector<Node>::const_iterator it = begin();
    vector<Node>::const_iterator prev = begin();

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while (prev != end())
    {
        prepend(it->get_value());
        prev = it;
        it++;
        erase(prev);
    }

}