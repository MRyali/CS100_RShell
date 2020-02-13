#ifndef ANDTOKEN_HPP
#define ANDTOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"

using namespace std;

class AndToken : public SeparatorToken {
    public:
        AndToken();
        AndToken(Token* first, Token* second);
        virtual bool execute();
};

#endif
