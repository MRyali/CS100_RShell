#include "Executor.hpp"

void Executor::execute() {
	//Creates a single SeparatorToken that chains together all tokens in command tokens list with the tokens in the separator token list
	if (separators.size() == 0) {
		//If there are not separators that means there is only one command
		//Just run the first command in commandTokens
		CommandToken* currCommand = commandTokens.front();
		commandTokens.pop_front();
		currCommand->execute();
	}
	else {
		//If there is something in separators, chaining is required
		
		//Create the initial SeparatorToken
		CommandToken* left = commandTokens.front();
		commandTokens.pop_front();
		
		CommandToken* right = commandTokens.front();
		commandTokens.pop_front();
		
		char* currSeparator = separators.front();
		separators.pop_front();
		
		if (strncmp(currSeparator, "&&", 2)) {
			AndToken* andToken = new AndToken(left, right);
			tokens.push_back(andToken);
		}
		
		if (strncmp(currSeparator, "||", 2)) {
			OrToken* orToken = new OrToken(left, right);
			tokens.push_back(orToken);
		}
		
		if (strncmp(currSeparator, ";", 2)) {
			SemiColonToken* semiColonToken = new SemiColonToken(left, right);
			tokens.push_back(semiColonToken);
		}
		
		//While there are still separators, chain them with the initial token
		while (separators.size() != 0) {
			//The previously created token will be the new left hand side token
			SeparatorToken* left = tokens.front();
			tokens.pop_front();
			
			CommandToken* right = commandTokens.front();
			commandTokens.pop_front();
			
			char* currSeparator = separators.front();
			separators.pop_front();
			
			if (strncmp(currSeparator, "&&", 2)) {
				AndToken* andToken = new AndToken(left, right);
				tokens.push_back(andToken);
			}
			
			if (strncmp(currSeparator, "||", 2)) {
				OrToken* orToken = new OrToken(left, right);
				tokens.push_back(orToken);
			}
			
			if (strncmp(currSeparator, ";", 2)) {
				SemiColonToken* semiColonToken = new SemiColonToken(left, right);
				tokens.push_back(semiColonToken);
			}
		}
		
		//Once everything is chained together, just run the first token in the list
		SeparatorToken* runToken = tokens.front();
		tokens.pop_front();
		runToken->execute();
	}
}