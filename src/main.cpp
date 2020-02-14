#include <iostream>

using namespace std;

#include "Tokenizer.hpp"
#include "Executor.hpp"

int main(int argc, char *argv[]) {
	while (true) {
		string inputStr;
		cout << "𓂀 ";
		getline(cin, inputStr);

		Tokenizer tokenizer = Tokenizer(inputStr);
		tokenizer.tokenize();

		Executor e = Executor(tokenizer.commandTokens, tokenizer.getConnectors());
		e.execute();
	}
}
