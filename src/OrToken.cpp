#include "OrToken.hpp"

using namespace std;

OrToken::OrToken () {}

OrToken::OrToken (Token* first, Token* second) {
    left = first;
    right = second;
}

int OrToken::execution() {
    int status = left->execute();
    if (status == 0) {
        return status;
    }
    else {
        status = right->execute();
        if (status == 0) {
            return status;
        }
    }
    return -1;
}
