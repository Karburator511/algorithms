#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "../stack/stack.h"
#include <string>


class Interpreter
{

private:

    Stack rods[3];


    bool move(int from, int to);


public:

    void loadInput(std::string file);

    void runScript(std::string file);

    void printResult();

};


#endif
