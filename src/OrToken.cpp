#include "OrToken.hpp"

using namespace std;

OrToken::OrToken() : SeparatorToken() {}

OrToken::OrToken (Token* first, Token* second) : SeparatorToken(first, second) {}

bool OrToken::execute() {
    bool status = leftSide->execute();
    if (status) {
        return status;
    }
    else {
        status = rightSide->execute();
        if (status) {
            return status;
        }
    }
    return false;
}
