#ifndef EMPTYRESULTEXCEPTION_H
#define EMPTYRESULTEXCEPTION_H

#include <string>
#include "Exception.h"

class EmptyResultException:public Exception {

	public:
		EmptyResultException(): Exception( "The result is an empty string!" ) {}
};

#endif
