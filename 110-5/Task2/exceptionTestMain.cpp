#include <iostream>

#include "exception.h"

int main()
{
	try {
		throw Exception("Test Exception");
	} catch (Exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
