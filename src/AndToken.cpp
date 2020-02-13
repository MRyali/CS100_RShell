#include "AndToken.hpp"

using namespace std;

AndToken::AndToken () {
}

AndToken::AndToken (Op* first, Op* second) {
    left = first;
    right = second;
    int execute()
}

int AndToken::execute() {
    int status = left->execute();
    if (status == 0) {
        status = right->execute();
        if (status == 0) {
            return status;
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}
