#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <deque>

#include "CommandToken.hpp"
#include "AndToken.hpp"
#include "OrToken.hpp"
#include "SeparatorToken.hpp"
#include "SemiColonToken.hpp"
#include "ExitToken.hpp"

using namespace std;

class Tokenizer {
    private:
        string inputStr;

    public:
        Tokenizer(string inputStr) {
            this->inputStr = inputStr;
        }

        deque<CommandToken*> commandTokens;
        deque<char*> connectors;

        bool containsComment(char* tokens);
        bool containsSemiColon(char* tokens);
        bool containsOrAnd(char* tokens);
        bool containsLeftPrecedence(char* tokens);
        bool containsRightPrecedence(char* tokens);
        
        void tokenize();
};

#endif
