add_executable(
    HanoiInterpreter

    main.cpp

    list/list.cpp
    stack/stack.cpp
    interpreter/interpreter.cpp
)


add_test(
    NAME HanoiTest
    COMMAND HanoiInterpreter
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
