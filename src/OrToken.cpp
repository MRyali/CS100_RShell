#include "OrToken.hpp"

using namespace std;

OrToken::OrToken () {}

OrToken::OrToken (Token* first, Token* second) {
    left = first;
    right = second;
}

bool OrToken::execute() {
    bool status = left->execute();
    if (status) {
        return status;
    }
    else {
        status = right->execute();
        if (status) {
            return status;
        }
    }
    return false;
}
