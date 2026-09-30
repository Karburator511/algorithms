#include "interpreter/interpreter.h"


int main()
{

    Interpreter interpreter;


    interpreter.loadInput("../input.txt");


    interpreter.runScript("../script.txt");


    interpreter.printResult();


    return 0;
}
