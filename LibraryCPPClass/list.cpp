#include "list.h"


List::Item::Item(Data data, List *owner)
{
    value = data;
    nextItem = nullptr;
    ownerList = owner;
}


List::Item *List::Item::next()
{
    return nextItem;
}


List::Item *List::Item::prev()
{
    if (ownerList == nullptr || ownerList->firstItem == this)
        return nullptr;

    Item *item = ownerList->firstItem;

    while (item != nullptr && item->nextItem != this)
        item = item->nextItem;

    return item;
}


Data List::Item::data() const
{
    return value;
}


List::List()
{
    firstItem = nullptr;
    lastItem = nullptr;
}


List::List(const List &a)
{
    firstItem = nullptr;
    lastItem = nullptr;

    copyFrom(a);
}


List &List::operator=(const List &a)
{
    if (this != &a)
    {
        clear();
        copyFrom(a);
    }

    return *this;
}


List::~List()
{
    clear();
}


void List::clear()
{
    while (firstItem != nullptr)
        erase_first();
}


void List::copyFrom(const List &a)
{
    const Item *item = a.firstItem;
    Item *last = nullptr;

    while (item != nullptr)
    {
        last = insert_after(last, item->data());
        item = item->nextItem;
    }
}


List::Item *List::first()
{
    return firstItem;
}


const List::Item *List::first() const
{
    return firstItem;
}


List::Item *List::last()
{
    return lastItem;
}


const List::Item *List::last() const
{
    return lastItem;
}


List::Item *List::insert(Data data)
{
    return insert_after(nullptr, data);
}


List::Item *List::insert_after(Item *item, Data data)
{
    Item *newItem = new Item(data, this);

    if (item == nullptr)
    {
        newItem->nextItem = firstItem;
        firstItem = newItem;

        if (lastItem == nullptr)
            lastItem = newItem;

        return newItem;
    }

    newItem->nextItem = item->nextItem;
    item->nextItem = newItem;

    if (lastItem == item)
        lastItem = newItem;

    return newItem;
}


List::Item *List::erase_first()
{
    if (firstItem == nullptr)
        return nullptr;

    Item *next = firstItem->nextItem;

    delete firstItem;

    firstItem = next;

    if (firstItem == nullptr)
        lastItem = nullptr;

    return firstItem;
}


List::Item *List::erase_next(Item *item)
{
    if (item == nullptr)
        return erase_first();

    if (item->nextItem == nullptr)
        return nullptr;

    Item *deletedItem = item->nextItem;
    Item *next = deletedItem->nextItem;

    item->nextItem = next;

    if (lastItem == deletedItem)
        lastItem = item;

    delete deletedItem;

    return next;
}
