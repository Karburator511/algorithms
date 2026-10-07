execute_process(
    COMMAND
        "${PROGRAM}"
        "${SCRIPT}"
        "${INPUT}"
    RESULT_VARIABLE result
    OUTPUT_VARIABLE actual
    ERROR_VARIABLE error
)

if (NOT result EQUAL 0)
    message(FATAL_ERROR "Program failed: ${error}")
endif()

file(READ "${EXPECTED}" expected)

if (NOT actual STREQUAL expected)
    message(
        FATAL_ERROR
        "Wrong output.\nExpected:\n${expected}\nActual:\n${actual}"
    )
endif()
