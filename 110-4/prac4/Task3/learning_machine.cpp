#include "global_includes.h"
#include <sstream>

#include "learning_machine.h"

LearningMachine::LearningMachine(double proficiency_)
{
  proficiency = proficiency_;
}

double LearningMachine::normalizeProficiency()
{
  if( proficiency < 0 )
    proficiency = 0;
  else if ( proficiency > 100 )
    proficiency = 100;

  return proficiency;
}

double LearningMachine::getProficiency()
{
  return proficiency;
}
