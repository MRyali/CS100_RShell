#include "AndToken.hpp"

using namespace std;

AndToken::AndToken() : SeparatorToken() {}

AndToken::AndToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool AndToken::execute() {
    bool status = leftSide->execute();
    if (status) {
        status = rightSide->execute();
        if (status) {
            return status;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
