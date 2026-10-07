#include "interpreter.h"

#include <fstream>
#include <iostream>
#include <iterator>


Interpreter::Interpreter()
{
    inputPosition = 0;
}


bool Interpreter::loadInput(const std::string &file)
{
    std::ifstream input(file, std::ios::binary);

    if (!input)
    {
        std::cerr << "Cannot open input file" << std::endl;
        return false;
    }

    inputData.assign(
        std::istreambuf_iterator<char>(input),
        std::istreambuf_iterator<char>()
    );

    inputPosition = 0;

    return true;
}


bool Interpreter::pushToRod(int rod, int value)
{
    if (rod < 0 || rod > 2)
        return false;

    if (value > 255)
        return false;

    if (!rods[rod].empty() && value > rods[rod].get())
        return false;

    rods[rod].push(value);

    return true;
}


int Interpreter::popFromRod(int rod)
{
    if (rods[rod].empty())
        return 255;

    int value = rods[rod].get();

    rods[rod].pop();

    return value;
}


bool Interpreter::execute(char command)
{
    if (command == '-')
    {
        int a = popFromRod(1);
        int b = popFromRod(1);

        if (!pushToRod(1, b))
            return false;

        return pushToRod(1, b - a);
    }


    if (command == '>')
    {
        int value = popFromRod(1);

        if (!pushToRod(1, value))
            return false;

        return pushToRod(1, value);
    }


    if (command == '<')
    {
        int first = popFromRod(1);
        int second = popFromRod(1);

        if (first != second)
            return false;

        return pushToRod(1, first);
    }


    if (command == '(')
    {
        int value = popFromRod(0);

        return pushToRod(1, value);
    }


    if (command == ')')
    {
        int value = popFromRod(1);

        return pushToRod(0, value);
    }


    if (command == '[')
    {
        int value = popFromRod(2);

        return pushToRod(1, value);
    }


    if (command == ']')
    {
        int value = popFromRod(1);

        return pushToRod(2, value);
    }


    if (command == '{')
    {
        int value = 0;

        if (inputPosition < inputData.size())
        {
            value =
                static_cast<unsigned char>(
                    inputData[inputPosition]
                );

            inputPosition++;
        }

        return pushToRod(1, value);
    }


    if (command == '}')
    {
        int value = popFromRod(1);

        outputData.insert(
            outputData.begin(),
            static_cast<char>(value)
        );

        return true;
    }


    return true;
}


bool Interpreter::runScript(const std::string &file)
{
    std::ifstream script(file, std::ios::binary);

    if (!script)
    {
        std::cerr << "Cannot open script file" << std::endl;
        return false;
    }

    outputData.clear();

    char command;

    while (script.get(command))
    {
        if (!execute(command))
        {
            std::cerr << "Invalid Hanoi operation" << std::endl;
            return false;
        }
    }

    return true;
}


void Interpreter::printResult() const
{
    if (!outputData.empty())
        std::cout << outputData << std::endl;


    for (int i = 0; i < 3; i++)
    {
        Stack copy = rods[i];

        while (!copy.empty())
        {
            std::cout
                << static_cast<char>(copy.get());

            copy.pop();
        }

        std::cout << std::endl;
    }
}
