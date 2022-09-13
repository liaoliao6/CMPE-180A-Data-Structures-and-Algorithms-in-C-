/*Implement the copy constructor of the Stack class.
 * Follow the pointers to the stack frames and copy each of them.*/

#include "stack.h"
#include <stdexcept>

using namespace std;

int StackFrame::frames = 0;

int Stack::stacks = 0;

Stack::Stack() : top(nullptr)
{
    stacks++;

}

Stack::~Stack()
{
    while (!empty()) pop();
}

Stack::Stack(const Stack& other)
{
    stacks++;

    if (other.top == NULL)
        return;

    // Create a temp variable since other.current doesn't move/change.
    StackFrame* tmp = other.top;

    // Allocate a new node in memory.
    StackFrame* head = new StackFrame;
    // Copy over the value.
    head->data = tmp->data;
    // Set the 'next' value to null (the loop will fill this in).
    head->link = nullptr;

    // Point 'current' to 'head'.
    StackFrame* current = head;

    // Move to next item in other's list.
    tmp = tmp->link;

    while (tmp != nullptr)
    {
        // Allocate new memory for a new 'node'.
        current->link = new StackFrame;
        // Point to this new 'node'.
        current = current->link;
        // Copy over the data.
        current->data = tmp->data;
        // By default set the 'next' to null.
        current->link = nullptr;
        // Move along other's list.
        tmp = tmp->link;
    }

    top = head;
}

bool Stack::empty() const
{
    return top == nullptr;
}

void Stack::push(string s)
{
    StackFrame* new_frame = new StackFrame();
    new_frame->data = s;
    new_frame->link = top;
    top = new_frame;
}

string Stack::pop()
{
    if (empty()) throw logic_error("Popping empty stack");

    string result = top->data;

    StackFrame* temp_ptr;
    temp_ptr = top;
    top = top->link;

    delete temp_ptr;

    return result;

}