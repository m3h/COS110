#ifndef CAESAR_H
#define CAESAR_H

#include <string>

#include "SubstitutionCipher.h"

using namespace std;

class Caesar: public SubstitutionCipher {

	protected:

		int shift;

	public:

		Caesar() { shift = 0; }

		void setShift(int);
		
		virtual char encodeChar(char);
		virtual char decodeChar(char);

};

#endif
