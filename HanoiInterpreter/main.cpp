#include "interpreter/interpreter.h"

#include <iostream>


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: HanoiInterpreter <script> <input>" << std::endl;
        return 1;
    }

    Interpreter interpreter;

    interpreter.loadInput(argv[2]);
    interpreter.runScript(argv[1]);
    interpreter.printResult();

    return 0;
}
