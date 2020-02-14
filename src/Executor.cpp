#include "Executor.hpp"

void Executor::execute() {
	//Creates a single SeparatorToken that chains together all tokens in command tokens list with the tokens in the separator token list
	
	string andLiteral = "&&";
	string orLiteral = "||";
	string semiLiteral = ";";
	
	if (separators.size() > 0) {
		//If there is something in separators, chaining is required

		//Create the initial SeparatorToken
		CommandToken* left = commandTokens.front();
		commandTokens.pop_front();

		CommandToken* right = commandTokens.front();
		commandTokens.pop_front();

		char* currSeparator = separators.front();
		separators.pop_front();

		if (currSeparator == andLiteral) {
			AndToken* andToken = new AndToken(left, right);
			tokens.push_back(andToken);
		}
		else if (currSeparator == orLiteral) {
			OrToken* orToken = new OrToken(left, right);
			tokens.push_back(orToken);
		}
		else if (currSeparator == semiLiteral) {
			SemiColonToken* semiColonToken = new SemiColonToken(left, right);
			tokens.push_back(semiColonToken);
		}

		//While there are still separators, chain them with the initial token
		while (separators.size() != 0) {
			//The previously created token will be the new left hand side token
			SeparatorToken* leftSide = tokens.front();
			tokens.pop_front();

			CommandToken* rightSide = commandTokens.front();
			commandTokens.pop_front();

			char* separator = separators.front();
			separators.pop_front();

			if (separator == andLiteral) {
				AndToken* andToken = new AndToken(leftSide, rightSide);
				tokens.push_back(andToken);
			}
			else if (separator == orLiteral) {
				OrToken* orToken = new OrToken(leftSide, rightSide);
				tokens.push_back(orToken);
			}
			else if (separator == semiLiteral) {
				SemiColonToken* semiColonToken = new SemiColonToken(leftSide, rightSide);
				tokens.push_back(semiColonToken);
			}
		}

		//Once everything is chained together, just run the first token in the list
		SeparatorToken* runToken = tokens.front();
		tokens.pop_front();
		runToken->execute();
	}
	else {
		//If there are not separators that means there is only one command
		//Just run the first command in commandTokens
		if (commandTokens.size() == 1) {
			CommandToken* currentCommand = commandTokens.front();
			commandTokens.pop_front();
			currentCommand->execute();
		}
	}
}
