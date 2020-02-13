#ifndef ORTOKEN_HPP
#define ORTOKEN_HPP

#include <iostream>
#include <vector>

//#include "SeparatorToken.hpp"
#include "Executor.hpp"

using namespace std;

class OrToken : public SeparatorToken {
    protected:
        Token* left;
        Token* right;
    public:
        OrToken();
        OrToken(Token* first, Token* second);
        bool execute();
};

#endif
