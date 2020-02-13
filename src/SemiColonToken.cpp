#include "SemiColonToken.hpp"

using namespace std;

SemiColonToken::SemiColonToken() : SeparatorToken() {}

SemiColonToken::SemiColonToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool SemiColonToken::execute() {
    bool status = leftSide->execute();
    status = rightSide->execute();
    if (!status) {
        return false;
    }
    return status;
}
