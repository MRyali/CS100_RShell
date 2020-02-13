#ifndef TOKEN_HPP
#define TOKEN_HPP

using namespace std;

class Token {
    public:
        virtual bool execute() = 0;
};

#endif