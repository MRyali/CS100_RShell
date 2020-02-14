#include "OrToken.hpp"

using namespace std;

OrToken::OrToken() : SeparatorToken() {}

OrToken::OrToken (Token* first, Token* second) : SeparatorToken(first, second) {}

bool OrToken::execute() {
    if (leftSide->execute();) {
        return true;
    }
    else {
        if (rightSide->execute()) {
            return true;
        }
    }
    return false;
}
