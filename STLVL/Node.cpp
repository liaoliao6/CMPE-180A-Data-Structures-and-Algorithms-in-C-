#include <iostream>
#include "Node.h"

long Node :: constructor_count = 0;
long Node :: copy_count = 0;
long Node :: assign_count = 0;
long Node :: destructor_count = 0;

Node::Node(const long the_value)
{
    value = the_value;
    constructor_count = constructor_count + 1;
}

Node::Node(const Node& other)
{
    value = other.value;
    copy_count = copy_count + 1;
}

Node&  Node:: operator = (const Node& rhs)
{
    value = rhs.value;
    assign_count = assign_count + 1;
    return *this;
}

 Node:: ~Node()
{
    destructor_count = destructor_count + 1;
}

long Node :: get_value() const
{
    return value;
}

long Node :: get_constructor_count()
{
    return constructor_count;
}

long Node :: get_copy_count()
{
    return copy_count;
}

long Node :: get_assign_count()
{
    return assign_count;
}

long Node :: get_destructor_count()
{
    return  destructor_count;
}

void Node :: reset()
{
    constructor_count = 0;
    copy_count = 0;
    assign_count = 0;
    destructor_count = 0;
}

bool Node :: operator ==(const Node& other) const
{
    return (value == other.value);
}

bool Node :: operator <=(const Node& other) const
{
    return (value <= other.value);
}

bool Node :: operator >=(const Node& other) const
{
    return (value >= other.value);
}