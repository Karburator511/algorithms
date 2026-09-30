#ifndef LIST_H
#define LIST_H

struct Node
{
    int value;
    Node* next;

    Node(int v)
    {
        value = v;
        next = nullptr;
    }
};


class List
{
private:
    Node* head;

public:
    List();

    ~List();

    void pushFront(int value);

    int popFront();

    bool empty();
};

#endif
