#ifndef TOKENIZER_TESTS_HPP
#define TOKENIZER_TESTS_HPP

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "gtest/gtest.h"
#include "Tokenizer.hpp"

TEST(TokenizerTest, TokenizerContainsComment) {
    string commentInput = "ls -a #This is a comment";
    Tokenizer t = Tokenizer(commentInput);

    char* commentArray = new char[24];
    strcpy(commentArray, commentInput.c_str());

    EXPECT_EQ(t.containsComment(commentArray), true);
}

TEST(TokenizerTest, TokenizerContainsSemiColon) {
    string semiInput = ";";
    Tokenizer t = Tokenizer(semiInput);

    char* semiArray = new char[2];
    strcpy(semiArray, semiInput.c_str());

    EXPECT_EQ(t.containsSemiColon(semiArray), true);
}

TEST(TokenizerTest, TokenizerContainsANDOR) {
    string input = "&&";
    Tokenizer t = Tokenizer(input);

    char* array2 = new char[2];
    strcpy(array2, input.c_str());

    EXPECT_EQ(t.containsOrAnd(array2), true);
}

TEST(TokenizerTest, TokenizerTestCommand) {
    string inputStr = "test -e names.txt";

    //If the program is not the exit command, pass the input to the Tokenizer class for parsing and classification
    Tokenizer* tokenizer = new Tokenizer(inputStr);
    tokenizer->tokenize();

    //Pass the tokenizer's classification deques to Executor, which runs each command in the proper order
    Executor e = Executor(tokenizer->finalCommandTokens, tokenizer->outerConnectors);
    EXPECT_EQ(e.execute(), true);
}

#endif
