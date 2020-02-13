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

using namespace std;

class Token {
    protected:
        string name;
    public:
        Token();
        virtual int execute() = 0;
};
