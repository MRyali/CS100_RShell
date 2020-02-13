#include "Token.hpp"

using namespace std;

class SeparatorToken : public Token {
    protected:
        Token* leftSide;
        Token* rightSide;
    public:
        SeparatorToken();
};
