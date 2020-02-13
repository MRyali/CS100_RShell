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

	//execvp/fork implementation

	// array for storing commands from user input
	pid_t wait_for_result;
	int status;
	// fork child process
	pid_t child_process = fork();
	//Error messages after fork updates
	if (child_process < 0) {
		perror("Fork Failed");
		// terminates program upon recieving fork failure with return val of 1
		exit(1);
	}
	else if (child_process == 0) {
	  // execute command from our array of strings
	  execvp(arr[0], arr);
	}
	else {
		// wait for child process to finish
		wait_for_result = waitpid(child_process, &status, WUNTRACED);
	}
	return true;
}
