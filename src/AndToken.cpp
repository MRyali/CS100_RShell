#include "AndToken.hpp"

using namespace std;

AndToken::AndToken () {}

AndToken::AndToken (Token* first, Token* second) {
    left = first;
    right = second;
}

bool AndToken::execute() {
    bool status = left->execute();
    if (status) {
        status = right->execute();
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
