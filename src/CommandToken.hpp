#ifndef COMMAND_TOKEN_HPP
#define COMMAND_TOKEN_HPP

#include "Token.hpp"
#include <deque>
#include <string>
#include <sys/wait.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>

using namespace std;

class CommandToken : public Token {
	private:
		char* commandName;
		deque<char*> arguments;
	
	public:
		CommandToken() {}
		
		CommandToken(char* command) {
			commandName = command;
		}	
		
		void addArgument(char* arg);
		string getName();
		virtual bool execute();
};

#endif