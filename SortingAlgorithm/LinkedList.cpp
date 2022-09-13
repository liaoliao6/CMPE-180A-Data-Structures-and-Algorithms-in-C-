#include <iostream>
#include "LinkedList.h"
using namespace std;

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

        // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)    //https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
{
    Node* slow = head;
    Node* fast = head -> next;
    int inc = 1;

    while(fast!= NULL)
    {
        fast = fast -> next;
        if(fast!= NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
            inc ++;
        }
    }
    list1.clear();
    list2.clear();
    list1.head = head;
    list1.tail = slow;
    list1.size = inc;
    list2.head = slow -> next;
    list2.tail = tail;
    list2.size = size - inc;
    //splitting
    slow -> next = NULL;
}

void LinkedList::concatenate(LinkedList& other_list)
{
    if(head == NULL)
    {
        head = other_list.head;
        tail = other_list.tail;
        size = other_list.size;
    }
    else
    {
        tail->next = other_list.head;
        tail = other_list.tail;
        size = size + other_list.size;
    }

}