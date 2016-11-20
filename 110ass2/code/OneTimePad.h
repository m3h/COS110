#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H

#include "Caesar.h"

using namespace std;


class OneTimePad: public Caesar {

	protected:

		long int seed;

	public:

		OneTimePad(long int in) { seed = in; }

		void setSeed(long int in) { seed = in; }

		virtual std::string encode(std::string in);
		virtual std::string decode(std::string in);
};

#endif
