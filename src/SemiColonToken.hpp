#ifndef ANDTOKEN_HPP
#define ANDTOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"
#include "Executor.hpp"

using namespace std;

class SemiColonToken : public SeparatorToken {
    protected:
        Token* left;
        Token* right;
    public:
        SemiColonToken();
        SemiColonToken(Token* first, Token* second);
        bool execute();
};

#endif
