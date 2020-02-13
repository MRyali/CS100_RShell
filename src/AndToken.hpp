#ifndef ANDTOKEN_HPP
#define ANDTOKEN_HPP

#include <iostream>
#include <vector>

#include "SeparatorToken.hpp"
#include "Executor.hpp"

using namespace std;

class AndToken : public base {
    protected:
        SeparatorToken* left;
        SeparatorToken* right;
    public:
        AndToken();
        AndToken(SeparatorToken* first, SeparatorToken* second);
        int execute();
};

#endif
