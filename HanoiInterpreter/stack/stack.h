#ifndef STACK_H
#define STACK_H

#include "../list/list.h"


class Stack
{
private:

    List list;


public:

    void push(int value);

    int pop();

    bool empty();

};

#endif
