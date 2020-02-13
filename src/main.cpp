#include <iostream>

#include "Tokenizer.hpp"
#include "Executor.hpp"

using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		string inputStr;
		cout << "$ ";
		getline(cin, inputStr);
		
		Tokenizer tokenizer = Tokenizer(inputStr);
		tokenizer.tokenize();
		
		Executor e = Executor(tokenizer.commandTokens, tokenizer.connectors);
		e.execute();
	}
}