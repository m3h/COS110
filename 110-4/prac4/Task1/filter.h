#ifndef FILTER_H
#define FILTER_H

#include <string>

class filter {

	public:
	filter() {};
	~filter() {};

	virtual std::string print(std::string s) = 0;
};

#endif
