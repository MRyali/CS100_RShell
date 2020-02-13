#include "SeparatorToken.hpp"

using namespace std;

SeparatorToken::SeparatorToken() {
	leftSide = nullptr;
	rightSide = nullptr;
}

SeparatorToken::SeparatorToken(Token* left, Token* right) {
	leftSide = left;
	rightSide = right;
}