#ifndef BACKWARDS_H
#define BACKWARDS_H

#include <string>

#include "filter.h"

class backwards: public filter {

	private:
	std::string strBackwards( std::string s );

	public:
	backwards() {};
	~backwards() {};

	virtual std::string print( std::string s );
};

#endif
