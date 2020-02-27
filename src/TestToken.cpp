#include "TestToken.hpp"

using namespace std;

TestToken::TestToken() : SeparatorToken() {}

TestToken::TestToken(Token* , Token* second) : SeparatorToken(first, second) {}

bool TestToken::execute() {
    if (// command is test) {
        return true;s
    }
    return false;
}
