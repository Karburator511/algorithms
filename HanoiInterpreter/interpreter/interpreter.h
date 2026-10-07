#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "stack.h"

#include <cstddef>
#include <string>


class Interpreter
{
private:
    Stack rods[3];

    std::string inputData;
    std::size_t inputPosition;

    std::string outputData;


    bool pushToRod(int rod, int value);

    int popFromRod(int rod);

    bool execute(char command);


public:
    Interpreter();

    bool loadInput(const std::string &file);

    bool runScript(const std::string &file);

    void printResult() const;
};


#endif
