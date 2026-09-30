#include "list.h"


List::List()
{
    head = nullptr;
}


List::~List()
{
    while(!empty())
        popFront();
}


void List::pushFront(int value)
{
    Node* node = new Node(value);

    node->next = head;

    head = node;
}


int List::popFront()
{
    if(head == nullptr)
        return -1;


    int value = head->value;

    Node* temp = head;

    head = head->next;

    delete temp;

    return value;
}


bool List::empty()
{
    return head == nullptr;
}
