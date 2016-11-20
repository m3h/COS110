#include "global_includes.h"
#include <sstream>

#include "lecturer_msc.h"

LecturerMsC::LecturerMsC(std::string name_, Gender gender_): Staff( name_, gender_, 70.0 ) { }

std::string LecturerMsC::teach(Person *student)
{
  return this->greet( student ) + " Great, let's start the lesson (LecturerMsC teaches). " + dynamic_cast<LearningMachine*>(student)->learn( this );
}

std::string LecturerMsC::learn(Person *student)
{
  double oldP = proficiency;

  proficiency += 1.25 * dynamic_cast<LearningMachine*>(student)->getSomeProficiency();

  normalizeProficiency();

  std::stringstream out;
  out << greet() << "'s Proficiency went from " << oldP << " to " << proficiency << ".";
  return out.str();
}

double LecturerMsC::getSomeProficiency()
{
  return proficiency * 0.05;
}
