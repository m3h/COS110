#include "global_includes.h"

#include "student.h"

Student::Student(std::string name_, Gender gender_): Person( name_, gender_ )
{

}

std::string Student::greet()
{
	return getTitle() + " " + this->Person::greet();
}

std::string Student::greet(Person *other)
{

	if( other == NULL ) {

		return "I don't greet null people!";

	} else if (  recognize( other ) == false ) {

		growAcquaintances();
		colleagues[numColleagues-1] = other;

		return "Hey dude, name's " + this->greet() + " what's yours? " + other->reply( this );

	} else {		// Person is recognized

		return "Hey dude, " + other->greet() + " nice to see you again. " + other->reply( this );

	}
}

std::string Student::work()
{

	return this->Person::greet() + " is " + this->Person::work()
	+ " into the Student Portal to do some work.";

}

std::string Student::getTitle()
{

	if( getGender() == male )
		return "young";
	else if ( getGender() == female )
		return "innocent";
	else
		return "brash";

}

std::string Student::reply(Person *other)
{
	if( other == NULL ) {

		return "I don't greet null people!";

	} else if (recognize(other) == false) {

		growAcquaintances();
		colleagues[numColleagues-1] = other;

		return "Hi " + other->greet() + ", " + this->Person::greet() + "\'s the name.";

	} else {		// person is recognized

		return "Hey dude, nice to see you again " + other->greet();

	}

}
