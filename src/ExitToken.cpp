#include "ExitToken.hpp"

ExitToken::ExitToken() {

}

bool ExitToken::execute() {
	exit(0);
}
