#ifndef CHARACTERNOTFOUNDEXCEPTION_H
#define CHARACTERNOTFOUNDEXCEPTION_H

#include <string>
#include "Exception.h"


class CharacterNotFoundException: public Exception {

	public:
		CharacterNotFoundException(): Exception("No character found!") {}

		CharacterNotFoundException( char c ): Exception("No character \'" + std::string(c, 1) + "\' found!") {}

};

#endif
