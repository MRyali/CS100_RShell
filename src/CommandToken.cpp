#include "CommandToken.hpp"

void CommandToken::addArgument(char* arg) {
	arguments.push_back(arg);
}

string CommandToken::getName() {
	return commandName;
}

bool CommandToken::execute() {
	arguments.push_back(NULL);
	char* arr[1000];
	
	int size = arguments.size();
	for (int i = 1; i < size + 1; i++) {
		arr[i] = arguments.front();
		arguments.pop_front();
	}
	arr[0] = commandName;
}
