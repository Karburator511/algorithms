#include "interpreter.h"

#include <fstream>
#include <iostream>



void Interpreter::loadInput(std::string file)
{
    std::ifstream input(file);


    int n;

    input >> n;


    for(int i=n;i>=1;i--)
    {
        rods[0].push(i);
    }
}



bool Interpreter::move(int from,int to)
{

    if(from < 0 || from > 2)
        return false;


    if(to < 0 || to > 2)
        return false;


    if(rods[from].empty())
        return false;



    int disk = rods[from].pop();


    rods[to].push(disk);


    return true;
}



void Interpreter::runScript(std::string file)
{

    std::ifstream script(file);


    std::string command;

    char from;

    char to;



    while(script >> command >> from >> to)
    {

        if(command == "MOVE")
        {

            int a = from - 'A';

            int b = to - 'A';



            if(!move(a,b))
            {
                std::cout << "Wrong move: "
                          << command << " "
                          << from << " "
                          << to << std::endl;
            }

        }

    }

}



void Interpreter::printResult()
{

    std::cout << "Final state:" << std::endl;



    for(int i=0;i<3;i++)
    {

        std::cout << char('A'+i) << ": ";


        Stack temp;



        while(!rods[i].empty())
        {

            temp.push(rods[i].pop());

        }



        while(!temp.empty())
        {

            std::cout << temp.pop() << " ";

        }



        std::cout << std::endl;

    }

}
