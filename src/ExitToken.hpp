#ifndef EXIT_HPP
#define EXIT_HPP

#include "CommandToken.hpp"

class ExitToken : public CommandToken {
	public:
		ExitToken();
		virtual bool execute();
};

#endif