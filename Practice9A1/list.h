
#ifndef PRACTICE9A1_LIST_H
#define PRACTICE9A1_LIST_H


#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);
void print(NodePtr head);



#endif //PRACTICE9A1_LIST_H
