
#ifndef UNEQUALSIZEEXCEPTION_H
#define UNEQUALSIZEEXCEPTION_H

#include <string>
#include "Exception.h"

class UnequalSizeException:public Exception {

	public:
		UnequalSizeException(): Exception("Strings are not the same size!") {}
};

#endif
