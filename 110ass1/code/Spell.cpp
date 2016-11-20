using namespace std;

#include "Spell.h"

#include <iomanip>

Spell::Spell( string nameIn, int difficultyLevelIn, int skillLevelIn )
{
	name = nameIn;
	difficultyLevel = difficultyLevelIn;
	skillLevel = skillLevelIn;
}


Spell::Spell(const Spell &sp )
{
	name = sp.name;
	difficultyLevel = sp.difficultyLevel;
	skillLevel = sp.skillLevel;
}

Spell::~Spell()
{
}

void Spell::setName(string n)
{
	name = n;
}

string Spell::getName() const
{
	return name;
}

void Spell::setDifficultyLevel(int d)
{
	difficultyLevel = d;
}

int Spell::getDifficultyLevel() const
{
	return difficultyLevel;
}

void Spell::setSkillLevel(int s)
{
	if( s >= 0 )
		skillLevel = s;
}

int Spell::getSkillLevel() const
{
	return skillLevel;
}

Spell& Spell::operator = (const Spell& sRight)
{
	name = sRight.getName();
	difficultyLevel = sRight.getDifficultyLevel();
	skillLevel = sRight.getSkillLevel();

	return *this;
}

// Pre-increment operator (’++’) that pre-increments the skillLevel of the specific Spell.
Spell& Spell::operator ++ ()
{
	setSkillLevel( skillLevel + 1);
	return *this;
}

// Post-increment operator (’++’) that post-increments the skillLevel of the specific Spell.
Spell Spell::operator ++ (int)
{
	Spell temp = *this;

	setSkillLevel( skillLevel + 1);
	return temp;
}

/* Pre-decrement operator (’--’) that pre-decrements the skillLevel of the specific Spell. Since you check with
setSkillLevel for bounds (negative values), it will make sense to check for bounds here too. Or you can just
call the setSkillLevel function with the new value and let setSKillLevel do the boundary checking. */
Spell& Spell::operator -- ()
{
	setSkillLevel( skillLevel - 1);
	return *this;
}

/* Post-decrement operator (’--’) that post-decrements the skillLevel of the specific Spell. Since you check with
setSkillLevel for bounds (negative values), it will make sense to check for bounds here too. Or you can just
call the setSkillLevel function with the new value and let setSKillLevel do the boundary checking. */
Spell Spell::operator -- (int)
{
	Spell temp = *this;

	setSkillLevel( skillLevel -1);
	return temp;
}

/* Minus equals (’− =’) operator that deducts a specified value from the skillLevel of the specific Spell. Since
you check with setSkillLevel for bounds (negative values), it will make sense to check for bounds here too.
Or you can just call the setSkillLevel function with the new value and let setSKillLevel do the boundary
checking. */
Spell Spell::operator -= (int skill)
{
	Spell temp = *this;

	temp.setSkillLevel( skillLevel - skill);
	skillLevel = temp.getSkillLevel();

	return temp;
}

/* For the ostream operator, the output should be as follows:
• The Spell’s name in a field width of 30, right justified, with no spaces, tabs or newlines afterwards
• The Spell’s difficultyLevel in a field width of 5, right justified, with no spaces, tabs or newlines afterwards
• The Spell’s skillLevel in a field width of 5, right justified, with no spaces, tabs or newlines afterwards */
ostream &operator << (ostream &strm, const Spell &obj)
{
	strm << right
	<< setw(30) << obj.getName()
	<< setw(5) << obj.getDifficultyLevel()
	<< setw(5) << obj.getSkillLevel();

	return strm;
}
