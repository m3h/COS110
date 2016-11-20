#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {

	private:
		std::string exString;
	public:
		Exception(std::string ex = "Error") { exString = ex; }
		std::string what() const { return exString; }
};

#endif
