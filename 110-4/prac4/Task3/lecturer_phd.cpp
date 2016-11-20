#include "global_includes.h"
#include <sstream>

#include "lecturer_phd.h"

LecturerPhD::LecturerPhD(std::string name_, Gender gender_): Staff(name_, gender_, 80.0 ) { }

std::string LecturerPhD::teach(Person *student)
{
  return greet( student ) + " Starting the lesson now (LecturerPhD teaches). " + dynamic_cast<LearningMachine*>(student)->learn( this );
}

std::string LecturerPhD::learn(Person *student)
{
  double oldP = proficiency;
  proficiency += 1.5 * dynamic_cast<LearningMachine*>(student)->getSomeProficiency();
  normalizeProficiency();

  std::stringstream out;

  out << this->greet() << "'s Proficiency went from " << oldP << " to " << proficiency << ".";
  return out.str();
}

double LecturerPhD::getSomeProficiency()
{
  return proficiency * 0.1;
}

std::string LecturerPhD::getTitle()
{
  return "Dr";
}
