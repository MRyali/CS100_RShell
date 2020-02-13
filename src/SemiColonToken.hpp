#ifndef SEMICOLONTOKEN_HPP
#define SEMICOLONTOKEN_HPP

#include <iostream>
#include <vector>

#include "Op.hpp"

using namespace std;

class SemiColonToken : public base {
    protected:
        Op* left;
        Op* right;
    public:
        SemiColonToken();
        SemiColonToken(Op* first, Op* second);
};

#endif
