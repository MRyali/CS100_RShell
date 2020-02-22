#ifndef TOKEN_HPP
#define TOKEN_HPP

using namespace std;

class Token {
    public:
        //Base structure for all tokens in this project
        //Every token must have the execute function
        virtual bool execute() = 0;
};

#endif
