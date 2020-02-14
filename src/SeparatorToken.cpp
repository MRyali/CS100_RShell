#include "SeparatorToken.hpp"

SeparatorToken::SeparatorToken() {
	leftSide = 0;
	rightSide = 0;
}

SeparatorToken::SeparatorToken(Token* left, Token* right) {
	leftSide = left;
	rightSide = right;
}
