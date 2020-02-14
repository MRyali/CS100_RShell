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

#endif
