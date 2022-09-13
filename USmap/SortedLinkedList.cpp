#include "SortedLinkedList.h"

void SortedLinkedList :: insert(Node *node)
{
    if (head == nullptr)    //node is the first element of the list
    {
        head = node;
    }
    else if (*head > *node) //node should be put before head
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node * pre = head;
        Node * post = head;

        while ((post != nullptr) && (*node > *post))
        {
            pre = post;
            post = post->next;
        }

        if (*node == *pre)  //two nodes at the same place
        {
            if (node->get_name()!="")
            {
                pre->set_name(node->get_name());    //replace the boundary node with city node
                pre->set_state(node->get_state());
            }
        }
        else
        {
            pre->next = node;   //insert node in the middle of the list
            node->next = post;
        }


    }
}

ostream& operator <<(ostream& outs, const SortedLinkedList& list)
{
    Node * p = list.head;
    Node * pre = p;
    int row = 0;
    int col = 0;

    while (p != nullptr)
    {
        while (row < p->get_row())  //find the right row
        {
            cout << endl;
            row ++;
            col = 0;
        }

        while (col < p->get_col())  //find the right col
        {
            cout << " ";
            col ++;
        }

        if (p->get_name() != "")    //check if output overlap with each other
        {
            if (((pre->get_col() + pre->get_name().size() + 4) <= p->get_col()) ||(p->get_row() != pre->get_row()))
            {
                outs << *p;
                col += p->get_name().size() + 4;
                pre = p;
            }
        }
        else
        {
            if (p->get_row() == 0)  //output the first line
            {
                outs << "#";
                col ++;
            }
            if (((pre->get_col() + pre->get_name().size() + 4) <= p->get_col()) ||(p->get_row() != pre->get_row()))
            {
                outs << "#";    //output other boundary
                col ++;
            }
        }


        p = p->next;
    }

    return outs;
}