add_executable(
    HanoiInterpreter
    main.cpp
    interpreter/interpreter.cpp
)

target_include_directories(
    HanoiInterpreter
    PRIVATE
    ../LibraryCPPClass
)

target_link_libraries(
    HanoiInterpreter
    LibraryCPPClass
)


function(add_hanoi_test NAME SCRIPT INPUT EXPECTED)

    add_test(
        NAME ${NAME}

        COMMAND
            ${CMAKE_COMMAND}
            "-DPROGRAM=$<TARGET_FILE:HanoiInterpreter>"
            "-DSCRIPT=${CMAKE_CURRENT_SOURCE_DIR}/tests/${SCRIPT}"
            "-DINPUT=${CMAKE_CURRENT_SOURCE_DIR}/tests/${INPUT}"
            "-DEXPECTED=${CMAKE_CURRENT_SOURCE_DIR}/tests/${EXPECTED}"
            -P
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/run_test.cmake"
    )

endfunction()


add_hanoi_test(
    TestHanoiExample
    example.script
    example.input
    example.expected
)

add_hanoi_test(
    TestHanoiDuplicate
    duplicate.script
    duplicate.input
    duplicate.expected
)

add_hanoi_test(
    TestHanoiMove12
    move12.script
    move12.input
    move12.expected
)

add_hanoi_test(
    TestHanoiMove23
    move23.script
    move23.input
    move23.expected
)
