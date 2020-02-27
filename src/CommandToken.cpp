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

	// handles "false" command
	string falseLiteral = "false";
	if (arr[0] == falseLiteral) {
		return false;
	}

	string testLiteral = "test";
	string fTestFlag = "-f";
	string dTestFlag = "-d";
	if (arr[0] == testLiteral) {
		if (size != 1) {
			if (arr[1] == fTestFlag) {
				cout << "Command was Test -f" << endl;
				return true;
			}
			else if (arr[1] == dTestFlag) {
				cout << "Command was Test -d" << endl;
				return true;
			}
			else {
				cout << "Command was Test -e" << endl;
				return true;
			}
			return false;
		}
		return false;
	}

	// array for storing commands from user input
	pid_t wait_for_result;
	int status;
	// fork child process
	pid_t child_process = fork();
	//Error messages after fork updates
	if (child_process < 0) {
		perror("Fork Failed");
		// terminates program upon recieving fork failure with return val of 1
		return false;
	}
	else if (child_process == 0) {
	  // execute command from our array of strings
	  // includes error handling for execvp
	  if (execvp(arr[0], arr) < 0) {
		  perror("Execvp Failed");
		  return false;
	  }
	}
	else {
		// wait for child process to finish
		wait_for_result = waitpid(child_process, &status, WUNTRACED);
	}
	return true;
}
