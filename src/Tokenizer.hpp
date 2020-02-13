#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <deque>

using namespace std;

class Tokenizer {
    private:
        deque<CommandToken*> commandTokens;
        deque<char*> connectors;
        
        string inputStr;

    public:
        Tokenizer(string inputStr) {
            this->inputStr = inputStr;
        }

        void tokenize();
};

#endif
