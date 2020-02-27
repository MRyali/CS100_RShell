#include "TestToken.hpp"

using namespace std;

TestToken::TestToken() : SeparatorToken() {}

TestToken::TestToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool TestToken::execute() {
    
}
