#ifndef SEPARATOR_TOKEN_HPP
#define SEPARATOR_TOKEN_HPP

#include "Token.hpp"

using namespace std;

class SeparatorToken : public Token {
    protected:
        Token* leftSide;
        Token* rightSide;
    public:
        SeparatorToken(); 
        SeparatorToken(Token* left, Token* right);
        
        virtual bool execute() = 0;
};

#endif
