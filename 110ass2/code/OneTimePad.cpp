#include <stdlib.h>
#include "OneTimePad.h"

std::string OneTimePad::encode( std::string in)
{
	srand( seed );

	int shift;
	Caesar c;

	for(int i = 0; i < in.length(); ++i) {

		shift = rand() % 94 + 1;

		c.setShift(shift);

		in[i] = c.encodeChar(in[i]);
	}

	return in;
}

std::string OneTimePad::decode( std::string in)
{
	srand( seed );

	int shift;
	Caesar c;

	for(int i = 0; i < in.length(); ++i) {

		shift = rand() % 94 + 1;

		c.setShift(shift);

		in[i] = c.decodeChar(in[i]);
	}

	return in;
}
