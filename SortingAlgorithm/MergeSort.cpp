/* Author: Jingjing Bu */
/* Reference: www.geeksforgeeks.org */

#include <string>
#include "MergeSort.h"

void MergeSort::run_sort_algorithm()
throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
    LinkedList sublist1, sublist2;

    // Base Case
    if ((list.get_head() == NULL) || (list.get_head()->next == NULL))
    {
        return;
    }
    // Splitting list
    list.split(sublist1, sublist2);


    // Recursively sorting two lists.
    mergesort(sublist1);
    mergesort(sublist2);

    // Sorted List.

    LinkedList newList;

    merge(newList, sublist1, sublist2);

    list.concatenate(newList);


}

Node* mergeNode(Node* h1, Node* h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    if (h1->element < h2->element)
    {
        h1->next = mergeNode(h1->next, h2);
        return h1;
    }
    else {
        h2->next = mergeNode(h1, h2->next);
        return h2;
    }
}

void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    Node * list1node = sublist1.get_head();
    Node * list2node = sublist2.get_head();

    Node * listNode = mergeNode(list1node, list2node);

    //list.clear();
    //list.add(listNode);
    compare_count = compare_count + sublist1.get_size();
    move_count = move_count + sublist1.get_size() + sublist2.get_size();

    Node *step = list.get_head();

    while(step != NULL)
    {
        cout << step->element.get_value()<<", ";
        step = step->next;
    }

}

void MergeSort::clear() { data.clear(); }