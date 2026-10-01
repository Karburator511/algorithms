#include "../stack/stack.h"

#include <iostream>


int main()
{
    Stack stack;

    if (!stack.empty())
        return 1;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    if (stack.pop() != 3)
        return 1;

    if (stack.pop() != 2)
        return 1;

    stack.push(5);

    if (stack.pop() != 5)
        return 1;

    if (stack.pop() != 1)
        return 1;

    if (!stack.empty())
        return 1;

    std::cout << "Stack tests passed" << std::endl;

    return 0;
}
