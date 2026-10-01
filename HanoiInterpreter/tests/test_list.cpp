#include "../list/list.h"

#include <iostream>


int main()
{
    List list;

    if (!list.empty())
    {
        std::cout << "List test failed" << std::endl;
        return 1;
    }

    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);

    if (list.empty())
    {
        std::cout << "List test failed" << std::endl;
        return 1;
    }

    if (list.popFront() != 30)
        return 1;

    if (list.popFront() != 20)
        return 1;

    list.pushFront(40);

    if (list.popFront() != 40)
        return 1;

    if (list.popFront() != 10)
        return 1;

    if (!list.empty())
        return 1;

    std::cout << "List tests passed" << std::endl;

    return 0;
}
