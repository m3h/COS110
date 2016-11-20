#include "global_includes.h"
#include <cmath>
#include <sstream>

#include "student.h"

Student::Student(std::string name_, Gender gender_): Person( name_, gender_ ), LearningMachine( 0.0 )
{

}

std::string Student::teach(Person *student)
{
	return this->greet( student ) + " Um, let's start *cough*  (Student teaches). " + dynamic_cast<LearningMachine*>(student)->learn( this ) + " Maybe I shouldn't teach :(";
}

std::string Student::learn(Person *teacher)
{
	double oldP = proficiency;
	proficiency += 1.1 * dynamic_cast<LearningMachine*>(teacher)->getSomeProficiency();

	normalizeProficiency();

	std::stringstream out;
	out << this->greet() << "'s Proficiency went from " << oldP << " to " << proficiency << ".";
	return out.str();

}

double Student::getSomeProficiency()
{
	return -10.0 / (sqrt(proficiency) + 1);
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

		return "Hey dude, nice to see you again " + other->greet() + ".";

	}

}
