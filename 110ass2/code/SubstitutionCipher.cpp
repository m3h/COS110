#include "SubstitutionCipher.h"

std::string SubstitutionCipher::encode(std::string in)
{
	for(int i = 0; i < in.length(); ++i) {

		in[i] = encodeChar(in[i]);

	}

	return in;
}

std::string SubstitutionCipher::decode(std::string in)
{
	for(int i = 0; i < in.length(); ++i) {

		in[i] = decodeChar(in[i]);

	}

	return in;
}
