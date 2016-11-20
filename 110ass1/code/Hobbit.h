/*
 * Class Hobbit
 */

#ifndef HOBBIT_H
#define	HOBBIT_H

#include <string>
#include "Wizard.h"

using namespace std;

class Hobbit{
private:
    string name;
public:
    Hobbit();
    ~Hobbit();
    void setName(string n);
    string getName() const;

    /*bool hasBeenSummoned(Wizard& w): sets whether a wizard has been summoned to a meeting or not. If a wizard
has lost the ability of casting 5 spells, a hobbit will summon the wizard to a meeting and will set the wizard’s vari-
able hasBeenSummoned to true. Therefore, this function must determine whether the variable hasBeenSummoned
should be set to true. The function returns the value of the wizard’s variable hasBeenSummoned.*/
    bool hasBeenSummoned(Wizard &w);

    /*bool hasCompletedTraining(Wizard& w): sets whether a wizard has completed new training (changes a wiz-
ard’s variable hasCompletedTraining). When the wizard has completed the training (i.e. when this function
is called), the hobbit resets the wizard’s numberOfLossedSpells back to zero, the wizard’s hasBeenSummoned
to false and the wizard’s hasCompletedTraining to true. The function returns the value of the wizard’s
hasCompletedTraining variabl*/
    bool hasCompletedTraining(Wizard& w);

    /*void dropWizardSpells(Wizard& w): the hobbit investigates whether a wizard should drop or remove any
spells. The hobbit goes through the wizard’s spells and if there is a spell with skillLevel of zero, it removes
that spell from the Wizard’s list of spells by calling the deleteSpell function of Wizard. After checking all the
spells, the hobbit calls its hasBeenSummoned function*/
    void dropWizardSpells(Wizard& w);
};

#endif	/* HOBBIT_H */
