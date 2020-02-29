#include <iostream>

using namespace std;

#include "Tokenizer.hpp"
#include "Executor.hpp"

int main(int argc, char *argv[]) {
	//Infinitely loops until the user types in the exit command, which is "exit" in this case
	while (true) {
		//Asks the user for input
		string inputStr;
		cout << "$ ";
		getline(cin, inputStr);

		//If the input is the exit command, immediately exit the program
		if (inputStr == "exit" || inputStr == "Exit") {
			exit(1);
		}

		//If the program is not the exit command, pass the input to the Tokenizer class for parsing and classification
		Tokenizer* tokenizer = new Tokenizer(inputStr);
		tokenizer->tokenize();

		//Pass the tokenizer's classification deques to Executor, which runs each command in the proper order
		Executor e = Executor(tokenizer->finalCommandTokens, tokenizer->outerConnectors);
		e.execute();
	}
}
