#include "Token.hpp"

using namespace std;

class SeparatorToken : public Token {
    protected:
        vector<Token*> leftSide;
        vector<Token*> rightSide;
    public:
        SeparatorToken();
};
