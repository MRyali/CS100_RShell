#include "OrToken.hpp"

using namespace std;

OrToken::OrToken () {
}

OrToken::OrToken (Op* first, Op* second) {
    left = first;
    right = second;
}

int OrToken::execute() {
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
