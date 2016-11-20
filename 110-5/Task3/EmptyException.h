#ifndef EMPTYEXCEPTION_H
#define EMPTYEXCEPTION_H

#include <string>
#include "Exception.h"

class EmptyException: public Exception {

	public:
		EmptyException(): Exception("The string is empty!") {}
};

#endif
