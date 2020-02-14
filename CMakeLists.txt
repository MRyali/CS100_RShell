CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(unit_tests)

SET(CMAKE_CXX_STANDARD 11)

SET(RSHELL_SOURCES
    src/main.cpp
    src/Tokenizer.cpp
    src/Executor.cpp
    src/CommandToken.cpp
    src/OrToken.cpp
    src/AndToken.cpp
    src/SemiColonToken.cpp
    src/ExitToken.cpp
    src/SeparatorToken.cpp
)

SET(UNIT_TEST_SOURCES
    src/unit_test.cpp
    unit_tests/tokenizer_tests.hpp
    src/Tokenizer.cpp
    src/Executor.cpp
    src/CommandToken.cpp
    src/OrToken.cpp
    src/AndToken.cpp
    src/SemiColonToken.cpp
    src/ExitToken.cpp
    src/SeparatorToken.cpp
)

ADD_EXECUTABLE (rshell ${RSHELL_SOURCES})

ADD_EXECUTABLE (test ${UNIT_TEST_SOURCES})

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
