#ifndef PRECEDENCETOKEN_HPP
#define PRECEDENCETOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"

using namespace std;

class PrecedenceToken : public SeparatorToken {
    public:
        PrecedenceToken();
        PrecedenceToken(Token* first, Token* second);
        virtual bool execute();
};

#endif
