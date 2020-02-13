#ifndef ANDTOKEN_HPP
#define ANDTOKEN_HPP

#include <iostream>
#include <vector>

#include "Op.hpp"

using namespace std;

class AndToken : public base {
    protected:
        Op* left;
        Op* right;
    public:
        AndToken();
        AndToken(Op* first, Op* second);
        int execute();
};

#endif
