#include "stack.h"


void Stack::push(int value)
{
    list.pushFront(value);
}


int Stack::pop()
{
    return list.popFront();
}


bool Stack::empty()
{
    return list.empty();
}
