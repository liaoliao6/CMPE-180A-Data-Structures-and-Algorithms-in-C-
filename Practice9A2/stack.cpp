#include "stack.h"

// Implement the destructor of the Stack class (without calling pop)

#include <stdexcept>
#include "stack.h"
using namespace std;

int StackFrame::frames = 0;

Stack::Stack() : top(nullptr)
{
}

Stack::~Stack()
{
    while (top != nullptr )
    {
        StackFrame * pre;
        pre = top;
        top = top -> link;
        pre -> ~StackFrame();
    }
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