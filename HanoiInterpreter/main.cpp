#include "interpreter/interpreter.h"

#include <iostream>


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout
            << "Usage: HanoiInterpreter <script> <input>"
            << std::endl;

        return 1;
    }


    Interpreter interpreter;


    if (!interpreter.loadInput(argv[2]))
        return 1;


    if (!interpreter.runScript(argv[1]))
        return 1;


    interpreter.printResult();


    return 0;
}
