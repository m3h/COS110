using namespace std;

#include "Hobbit.h"

Hobbit::Hobbit()
{
	name = "Gerald";
}

Hobbit::~Hobbit()
{

}

void Hobbit::setName(string n)
{
	name = n;
}

string Hobbit::getName() const
{
	return name;
}

/*bool hasBeenSummoned(Wizard& w): sets whether a wizard has been summoned to a meeting or not. If a wizard
has lost the ability of casting 5 spells, a hobbit will summon the wizard to a meeting and will set the wizard’s vari-
able hasBeenSummoned to true. Therefore, this function must determine whether the variable hasBeenSummoned
should be set to true. The function returns the value of the wizard’s variable hasBeenSummoned.*/
bool Hobbit::hasBeenSummoned(Wizard &w)
{
	if( w.numberOfLossedSpells >= 5 )
		w.hasBeenSummoned = true;

	return w.hasBeenSummoned;
}

/*bool hasCompletedTraining(Wizard& w): sets whether a wizard has completed new training (changes a wiz-
ard’s variable hasCompletedTraining). When the wizard has completed the training (i.e. when this function
is called), the hobbit resets the wizard’s numberOfLossedSpells back to zero, the wizard’s hasBeenSummoned
to false and the wizard’s hasCompletedTraining to true. The function returns the value of the wizard’s
hasCompletedTraining variabl*/
bool Hobbit::hasCompletedTraining(Wizard& w)
{
	w.numberOfLossedSpells = 0;
	w.hasBeenSummoned = false;
	w.hasCompletedTraining = true;

	return w.hasCompletedTraining;
}

/*void dropWizardSpells(Wizard& w): the hobbit investigates whether a wizard should drop or remove any
spells. The hobbit goes through the wizard’s spells and if there is a spell with skillLevel of zero, it removes
that spell from the Wizard’s list of spells by calling the deleteSpell function of Wizard. After checking all the
spells, the hobbit calls its hasBeenSummoned function*/
void Hobbit::dropWizardSpells(Wizard& w)
{
	for(int i = 0; i < w.maxNumberOfSpells; ++i) {
		if( (w.getSpell(i).getName() != "") && (w.getSpell(i).getSkillLevel() <= 0) ) {
			w.deleteSpell( w.getSpell(i).getName() );
		}
	}

	hasBeenSummoned(w);
}
