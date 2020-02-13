#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <vector>

#include "SeparatorToken.hpp"

using namespace std;

class Executor : public base {
    protected:

    public:
        Executor();
        int execute(vector<char*>);
};

#endif
