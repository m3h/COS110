#include "global_includes.h"

#include "person.h"


size_t Person::empNoCounter = 12345678;


Person::Person(std::string name_, Gender gender_)
{
	name = name_;
	gender = gender_;

	numColleagues = 0;
	colleagues = 0;
	empNo = empNoCounter++;
}

Person::~Person()
{
	delete [] colleagues;
}

size_t Person::getNumColleagues()
{
	return this->numColleagues;
}

std::string Person::greet()
{
	return this->name;
}

std::string Person::work()
{
	std::stringstream out;

	out << "logging in with employee number "
		<< std::right << std::setfill('0') << std::setw(8) << empNo;

	return out.str();
}

Person& Person::operator[] (size_t i)
{
	return *(this->colleagues[i]);
}

void Person::growAcquaintances()
{
	Person **temp = new Person* [++numColleagues];

	for(size_t i = 0; i < numColleagues-1; ++i) {
		temp[i] = colleagues[i];
	}

	delete [] colleagues;
	colleagues = temp;
}

bool Person::recognize(Person * other)
{
	for(size_t i = 0; i < numColleagues; ++i) {
		if( colleagues[i] == other )
			return true;
	}

	return false;
}

Person::Gender Person::getGender()
{
	return this->gender;
}
