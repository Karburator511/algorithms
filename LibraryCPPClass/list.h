#ifndef LIST_H
#define LIST_H

typedef int Data;

class List
{
public:
    class Item
    {
    public:
        Item *next();
        Item *prev();
        Data data() const;

    private:
        Item(Data data, List *owner);

        Data value;
        Item *nextItem;
        List *ownerList;

        friend class List;
    };

    List();
    List(const List &a);
    List &operator=(const List &a);
    ~List();

    Item *first();
    const Item *first() const;

    Item *last();
    const Item *last() const;

    Item *insert(Data data);
    Item *insert_after(Item *item, Data data);

    Item *erase_first();
    Item *erase_next(Item *item);

private:
    Item *firstItem;
    Item *lastItem;

    void clear();
    void copyFrom(const List &a);
};

#endif
