#ifndef ORTOKEN_HPP
#define ORTOKEN_HPP

#include <iostream>
#include <vector>

#include "Op.hpp"

using namespace std;

class OrToken : public base {
    protected:
        Op* left;
        Op* right;
    public:
        OrToken();
        OrToken(Op* first, Op* second);
        int execute();
};

#endif
