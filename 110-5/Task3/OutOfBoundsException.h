#ifndef OUTOFBOUNDSEXCEPTION_H 
#define OUTOFBOUNDSEXCEPTION_H 

#include <string>
#include "Exception.h"

class OutOfBoundsException: public Exception {

	public:
		OutOfBoundsException(): Exception("Index out of bounds!") {}
};

#endif
