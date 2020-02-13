#ifndef SEMI_COLON_TOKEN_HPP
#define SEMI_COLON_TOKEN_HPP

#include <iostream>

#include "SeparatorToken.hpp"

using namespace std;

class SemiColonToken : public SeparatorToken {
    public:
        SemiColonToken();
        SemiColonToken(Token* first, Token* second);
        virtual bool execute();
};

#endif
