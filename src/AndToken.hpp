#ifndef ANDTOKEN_HPP
#define ANDTOKEN_HPP

#include <iostream>
#include <vector>

//#include "SeparatorToken.hpp"
#include "Executor.hpp"

using namespace std;

class AndToken : public SeparatorToken {
    protected:
        Token* left;
        Token* right;
    public:
        AndToken();
        AndToken(Token* first, Token* second);
        bool execute();
};

#endif
