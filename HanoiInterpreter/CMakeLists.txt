cmake_minimum_required(VERSION 3.15)

project(HanoiInterpreter)


set(CMAKE_CXX_STANDARD 17)



add_executable(
HanoiInterpreter

main.cpp

list/list.cpp

stack/stack.cpp

interpreter/interpreter.cpp
)



enable_testing()


add_test(
NAME BasicTest
COMMAND HanoiInterpreter
)

