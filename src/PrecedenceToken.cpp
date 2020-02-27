#include "PrecedenceToken.hpp"

using namespace std;

PrecedenceToken::PrecedenceToken() : SeparatorToken() {}

PrecedenceToken::PrecedenceToken(Token* first, Token* second) : SeparatorToken(first, second) {}

bool PrecedenceToken::execute() {
    
}
