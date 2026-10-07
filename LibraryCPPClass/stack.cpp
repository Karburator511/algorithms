#include "stack.h"


Stack::Stack()
{
}


Stack::Stack(const Stack &a)
    : list(a.list)
{
}


Stack &Stack::operator=(const Stack &a)
{
    if (this != &a)
        list = a.list;

    return *this;
}


Stack::~Stack()
{
}


void Stack::push(Data data)
{
    list.insert(data);
}


Data Stack::get() const
{
    const List::Item *item = list.first();

    if (item == nullptr)
        return Data();

    return item->data();
}


void Stack::pop()
{
    if (!empty())
        list.erase_first();
}


bool Stack::empty() const
{
    return list.first() == nullptr;
}
