#include "list.h"

/*
   This function removes every even element from the given linked
   list. For example, if a list contains 16 26 25 12 11 (and then NULL),
   it is modified to contain 25 11 (and then NULL).
*/
void remove_every_even(NodePtr& head)
{
    NodePtr pre = new Node;
    NodePtr post = new Node;


    while ((head != NULL) && (head->data % 2 == 0))
        head = head->link;

        pre = head;
        post = head;

    while (post != NULL)
    {
        if (post->data %2 != 0)
        {
            pre = post;
            post = post->link;
        }
        else
        {
            pre->link = post->link;
            post = post->link;
        }

    }
}
