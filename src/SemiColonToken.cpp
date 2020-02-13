#include "SemiColonToken.hpp"

using namespace std;

SemiColonToken::SemiColonToken () {
}

SemiColonToken::SemiColonToken (Op* first, Op* second) {
    left = first;
    right = second;
}
