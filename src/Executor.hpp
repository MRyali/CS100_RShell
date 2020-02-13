#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <iostream>
#include <vector>

#include "AndToken.hpp"
#include "OrToken.hpp"
#include "SemiColon.hpp"

using namespace std;

class Executor : public base {
    protected:

    public:
        EXecutor();
        int execute(vector<char*>);
};

#endif
