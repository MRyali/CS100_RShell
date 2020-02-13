#include "SemiColonToken.hpp"

using namespace std;

SemiColonToken::SemiColonToken() {}

SemiColonToken::SemiColonToken(Token* first, Token* second) {
    left = first;
    right = second;
}

bool SemiColonToken::execute() {
    bool status = left->execute();
    status = right->execute();
    if (!status) {
        return false;
    }
    return status;
}
