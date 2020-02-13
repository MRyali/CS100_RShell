#include "CommandToken.hpp"

void CommandToken::addArgument(char* arg) {
	arguments.push_back(arg);
}

string CommandToken::getName() {
	return commandName;
}

bool CommandToken::execute() {
	return true;
}