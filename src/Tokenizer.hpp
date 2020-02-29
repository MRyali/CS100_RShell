#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>

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
        
        string andLiteral = "&&";
        string orLiteral = "||";
        string semiLiteral = ";";

    public:
        deque<CommandToken*> commandTokens;
        deque<Token*> finalCommandTokens;
        
        deque<char*> connectors;
        deque<char*> outerConnectors;
        
        Tokenizer(string inputStr) {
            this->inputStr = inputStr;
        }

        bool precedenceFiltered;

        bool containsComment(char* tokens);
        bool containsSemiColon(char* tokens);
        bool containsOrAnd(char* tokens);
        bool containsDash(char* tokens);
        
        bool containsLeftPrecedence(char* tokens);
        bool containsRightPrecedence(char* tokens);
        bool containsLeftBracket(char* tokens);
        bool containsRightBracket(char* tokens);
        
        void tokenize();
};

#endif
