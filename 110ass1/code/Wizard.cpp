/*
 * Class Wizard cpp
 * Reece Volker, u16312572, 3/09/2016
 */

using namespace std;

#include "Wizard.h"
#include "Spell.h"

void Wizard::initialiseSpells( Spell* spells, int maxNumberOfSpells ) {
	Spell defaultSpell("");
	for(int i = 0; i < maxNumberOfSpells; ++i) {
		spells[i] = defaultSpell;
	}
}

Wizard::Wizard()
{
	numberOfSpells = 0;
	maxNumberOfSpells = 10;
	hasBeenSummoned = false;
	age = 20;
	numberOfLossedSpells = 0;
	hasCompletedTraining = false;
/*
	spells = new Spell[maxNumberOfSpells];
	Spell defaultS("");
	for(int i = 0; i < maxNumberOfSpells; ++i) {
		spells[i] = defaultS;
	}
*/
	spells = new Spell[maxNumberOfSpells];
	initialiseSpells( spells, maxNumberOfSpells );
}

Wizard::Wizard( const Wizard& w )
{
	numberOfSpells = w.numberOfSpells;
	maxNumberOfSpells = w.maxNumberOfSpells;
	hasBeenSummoned = w.hasBeenSummoned;
	age = w.age;
	numberOfLossedSpells = w.numberOfLossedSpells;

	spells = new Spell[maxNumberOfSpells];
	for(int i = 0; i < maxNumberOfSpells; ++i) {
		spells[i] = w.spells[i];
	}
}

Wizard::~Wizard()
{
	delete [] spells;
}

void Wizard::addSpell(const Spell& s)
{
	// If duplicate is added, check for skill level
	for(int i = 0; i < maxNumberOfSpells; ++i) {
		if( spells[i].getName() == s.getName() ) {
			if( s.getSkillLevel() > spells[i].getSkillLevel() )
				spells[i] = s;
			return;
		}
	}
	if( numberOfSpells == maxNumberOfSpells ) {	// add a slot to max

		Spell* temp = new Spell [++maxNumberOfSpells];
		//initialiseSpells( spells, maxNumberOfSpells );
		//
		for(int i = 0; i < maxNumberOfSpells - 1; ++i) {
			temp[i] = spells[i];
		}

		Spell defaultSpell("");
		temp[maxNumberOfSpells-1] = defaultSpell;

		delete [] spells;
		spells = temp;
	}

	int emptySpellIndex = -1;

	for(int i = 0; i < maxNumberOfSpells; ++i) {
		if( spells[i].getName() == "" ) {
			emptySpellIndex = i;
			break;
		}
	}

	if( emptySpellIndex == -1 ) {
		printf("Error emptySpellIndex -1\n");
		exit(EXIT_FAILURE);
	}

	spells[emptySpellIndex] = s;
	++numberOfSpells;
}

void Wizard::deleteSpell(string name)
{
	//cout << "N!" << name << endl;
	Spell temp("");

	for(int i = 0; i < maxNumberOfSpells; ++i) 
	{
		if( spells[i].getName() == name ) 
		{
			spells[i] = temp;
			--numberOfSpells;
			++numberOfLossedSpells;

			//iicout << "deleting: " << spells[i].getName() << endl;
			//cout << numberOfSpells << endl;
		}
	}

}

int Wizard::getNumberOfSpells() const
{
	return numberOfSpells;
}

void Wizard::setMaxNumberOfSpells(int m)
{
	if( m < 1 ) {	// shouldn't happen
		return;
	}

	Spell* temp = new Spell[m];
/*
	Spell defaultSpell("");
	for(int i = 0; i < maxNumberOfSpells; ++i) {
		spells[i] = defaultSpell;
	}
*/

	if( m < maxNumberOfSpells ) {	// delete lost spells
		for(int i = m; i < maxNumberOfSpells; ++i ) {
			Spell t = getSpell( i );
			if( t.getName() != "" )
				deleteSpell( t.getName() );
		}
	}

	int i;
	for(i = 0; i < m && i < maxNumberOfSpells; ++i) {
		temp[i] = spells[i];
	}

	Spell defaultSpell("");
	for( ; i < m; ++i) {
		temp[i] = defaultSpell;
	}

	delete [] spells;
	spells = temp;

	maxNumberOfSpells = m;
}

int Wizard::getMaxNumberOfSpells() const
{
	return maxNumberOfSpells;
}

void Wizard::setAge(int a)
{
	age = a;
}

int Wizard::getAge() const
{
	return age;
}

int Wizard::getNumberOfLossedSpells() const
{
	return numberOfLossedSpells;
}

void Wizard::setNumberOfLossedSpells(int num)
{
	numberOfLossedSpells = num;
}

Spell& Wizard::getSpell(int index) const
{
	if( index > 0 && index < maxNumberOfSpells ) {
		return spells[index];
	}

	return spells[0];
}

bool Wizard::getHasBeenSummoned() const
{
	return hasBeenSummoned;
}

bool Wizard::getHasCompletedTraining() const
{
	return hasCompletedTraining;
}

void Wizard::setHasCompletedTraining(bool b)
{
	hasCompletedTraining = b;
}

void Wizard::setHasBeenSummoned(bool b)
{
	hasBeenSummoned = b;
}

// Task 2
bool Wizard::operator > (const Wizard &wiz2) const
{
	int wiz1Won = 0;
	int wiz2Won = 0;

	for(int i = 0; i < maxNumberOfSpells; ++i) {	// Loop through all of wiz1 spells
		Spell wiz1Spell = spells[i];
		//cout << wiz1Spell.getName() << " " << wiz1Spell.getDifficultyLevel() << endl;
		for(int j = 0; j < wiz2.getMaxNumberOfSpells(); ++j) {	// Loop through all of wiz2 spells
			Spell wiz2Spell = wiz2.getSpell(j);

			if(  wiz1Spell.getName() == wiz2Spell.getName() ) {

				//SPells are the same. Now compare
				if( wiz1Spell.getSkillLevel() == wiz2Spell.getSkillLevel() )
					;
				else if( wiz1Spell.getSkillLevel() > wiz2Spell.getSkillLevel() )
					++wiz1Won;
				else
					++wiz2Won;
			}
		}
	}


	if( wiz1Won > wiz2Won )
		return true;
	else
		return false;
}


bool Wizard::operator < (const Wizard &wiz2) const
{

	int wiz1Won = 0;
	int wiz2Won = 0;

	for(int i = 0; i < maxNumberOfSpells; ++i) {	// Loop through all of wiz1 spells
		Spell wiz1Spell = spells[i];
		//cout << wiz1Spell.getName() << " " << wiz1Spell.getDifficultyLevel() << endl;
		for(int j = 0; j < wiz2.getMaxNumberOfSpells(); ++j) {	// Loop through all of wiz2 spells
			Spell wiz2Spell = wiz2.getSpell(j);

			if(  wiz1Spell.getName() == wiz2Spell.getName() ) {

				//SPells are the same. Now compare
				if( wiz1Spell.getSkillLevel() == wiz2Spell.getSkillLevel() )
					;
				else if( wiz1Spell.getSkillLevel() < wiz2Spell.getSkillLevel() )
					++wiz1Won;
				else
					++wiz2Won;
			}
		}
	}


	if( wiz1Won > wiz2Won )
		return true;
	else
		return false;
}

void Wizard::operator + (const Spell &spell)
{
	addSpell( spell );

}

void Wizard::operator - (const string spellName)
{
	deleteSpell( spellName );

}
