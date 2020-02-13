#include "Executor.hpp"

void Executor::execute() {
	if (separators.size() > 0) {
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
		
		while (separators.size() != 0) {
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
		
		SeparatorToken* runToken = tokens.front();
		tokens.pop_front();
		runToken->execute();
	}
	else {
		CommandToken* currCommand = commandTokens.front();
		commandTokens.pop_front();
		currCommand->execute();
	}
}