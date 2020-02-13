#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include "Tokenizer.hpp"

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

class Executor {
	private:
		deque<CommandToken*> commandTokens;
		deque<char*> separators;
		deque<Token*> tokens;
	
	public:
		Executor(deque<CommandToken*> commandTokenDeque, deque<char*> connectorDeque) {
			commandTokens = commandTokenDeque;
			connectors = connectorDeque;
		}
		
		void execute();
};

#endif