#include "global_includes.h"


#include "staff.h"

Staff::Staff(std::string name_, Gender gender_, double proficiency_): Person( name_, gender_), LearningMachine( proficiency_ )
{

}

std::string Staff::greet()
{

  return getTitle() + " " + this->Person::greet();

}

std::string Staff::greet(Person *other)
{
  if( other == NULL ) {

    return "I don't greet null people!";

  } else if ( recognize( other ) == false ) {

    growAcquaintances();
    colleagues[numColleagues-1] = other;

    return "Good day, I am " + this->greet() + " and you are? " + other->reply( this );

  } else {

    return "Hello " + other->greet() + " we meet again. " + other->reply( this );

  }
}

std::string Staff::work()
{

  return this->Person::greet() + " is " + this->Person::work() + " into the Staff Portal to do some work.";

}

std::string Staff::getTitle()
{

  if( getGender() == male )
    return "Mr";
  else if ( getGender() == female )
    return "Ms";
  else
    return "Triblaster";
}

std::string Staff::reply(Person *other)
{
  if( other == NULL ) {

    return "I don't greet null people!";

  } else if ( recognize( other ) == false ) {

    growAcquaintances();

    colleagues[numColleagues-1] = other;

    return "I am " + this->greet() + ", nice to meet you " + other-> greet() + ".";

  } else {

    return "Hello " + other->greet() + " we meet again.";

  }
}
