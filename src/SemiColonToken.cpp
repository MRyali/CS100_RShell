#include "SemiColonToken.hpp"

using namespace std;

SemiColonToken::SemiColonToken() : SeparatorToken() {}

SemiColonToken::SemiColonToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool SemiColonToken::execute() {
    leftSide->execute();
    return rightSide->execute();
}
