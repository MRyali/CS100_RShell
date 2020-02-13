#ifndef ORTOKEN_HPP
#define ORTOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"
#include "Executor.hpp"

using namespace std;

class OrToken : public base {
    protected:
        SeparatorToken* left;
        SeparatorToken* right;
    public:
        OrToken();
        OrToken(SeparatorToken* first, SeparatorToken* second);
        int execute();
};

#endif
