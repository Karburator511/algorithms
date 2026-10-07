add_executable(TestListCPPClass list.cpp)
target_include_directories(TestListCPPClass PUBLIC ..)
target_link_libraries(TestListCPPClass LibraryCPPClass)
add_test(NAME TestListCPPClass COMMAND TestListCPPClass)

add_executable(TestStackCPPClass stack.cpp)
target_include_directories(TestStackCPPClass PUBLIC ..)
target_link_libraries(TestStackCPPClass LibraryCPPClass)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(TestStackCPPClass PRIVATE -Wno-self-assign-overloaded)
endif()

add_test(NAME TestStackCPPClass COMMAND TestStackCPPClass)
