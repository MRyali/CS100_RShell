#include "AndToken.hpp"

using namespace std;

AndToken::AndToken() : SeparatorToken() {}

AndToken::AndToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool AndToken::execute() {
    if (leftSide->execute()) {
        if (rightSide->execute()) {
            return true;
        }
        return false;
    }
    return false;
}
