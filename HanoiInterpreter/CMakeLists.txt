add_executable(
    HanoiInterpreter
    main.cpp
    list/list.cpp
    stack/stack.cpp
    interpreter/interpreter.cpp
)


add_executable(
    TestHanoiList
    tests/test_list.cpp
    list/list.cpp
)


add_executable(
    TestHanoiStack
    tests/test_stack.cpp
    list/list.cpp
    stack/stack.cpp
)


add_test(
    NAME TestHanoiList
    COMMAND TestHanoiList
)


add_test(
    NAME TestHanoiStack
    COMMAND TestHanoiStack
)


add_test(
    NAME TestHanoiOneDisk
    COMMAND HanoiInterpreter
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/script1.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/input1.txt
)

set_property(
    TEST TestHanoiOneDisk
    PROPERTY PASS_REGULAR_EXPRESSION "C: 1"
)


add_test(
    NAME TestHanoiTwoDisks
    COMMAND HanoiInterpreter
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/script2.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/input2.txt
)

set_property(
    TEST TestHanoiTwoDisks
    PROPERTY PASS_REGULAR_EXPRESSION "C: 2 1"
)


add_test(
    NAME TestHanoiThreeDisks
    COMMAND HanoiInterpreter
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/script3.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/input3.txt
)

set_property(
    TEST TestHanoiThreeDisks
    PROPERTY PASS_REGULAR_EXPRESSION "C: 3 2 1"
)
