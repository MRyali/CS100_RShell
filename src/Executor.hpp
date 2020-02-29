#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <iostream>
#include <deque>
#include <cstring>
#include <string>

#include "CommandToken.hpp"
#include "SeparatorToken.hpp"
#include "AndToken.hpp"
#include "OrToken.hpp"
#include "SemiColonToken.hpp"

using namespace std;

class Executor {
	private:
		bool precedenceFiltered;
		deque<Token*> commandTokens;
		deque<char*> separators;
		deque<SeparatorToken*> tokens;
	
	public:
		Executor(deque<Token*> commandTokenDeque, deque<char*> connectorDeque) {
			commandTokens = commandTokenDeque;
			
			separators = connectorDeque;
		}
		
		void execute();
};

#endif