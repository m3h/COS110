#ifndef TITLECASE_H
#define TITLECASE_H

#include <string>

#include "filter.h"

class titleCase: public filter {

	private:
	std::string strToTitle( std::string s );

	public:
	titleCase() {};
	~titleCase() {};

	virtual std::string print( std::string s );
};

#endif
