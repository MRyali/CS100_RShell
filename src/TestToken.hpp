#ifndef TESTTOKEN_HPP
#define TESTTOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"

using namespace std;

class TestToken : public SeparatorToken {
    public:
        TestToken();
        TestToken(Token* first, Token* second);
        virtual bool execute();
};

#endif
