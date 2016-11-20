#include <iostream>

#include "Caesar.h"

void shiftCheck(int sh)
{
	if( sh <= 0 )
		throw "Please provide a positive shift value";
	else if( sh > 94 )
		throw "Maximum shift is 94 for ASCII, please try again";
}

void Caesar::setShift(int sh)
{
	bool notSet = true;

	while( notSet ) {

		notSet = false;

		try {
			shiftCheck( sh );
		} catch( const char *msg ) {

			std::cout << msg << std::endl;
			std::cin >> sh;

			notSet = true;
		}

	}

	shift = sh;
}

char Caesar::encodeChar(char c)
{
	if( shift == 0 ) {
		int sh;
		std::cout << "Please provide a positive shift value" << endl;
		std::cin >> sh;
		setShift( sh );
	}

	int enc = c + shift;

	if (enc > 126)
		enc = enc - 126 + 32 - 1;

	return enc;
}

char Caesar::decodeChar(char c)
{
	int dec = static_cast<int>(c) - shift;

	if( dec < 32 )
		dec = 126 - 32 + 1 + dec;

	return dec;
}
