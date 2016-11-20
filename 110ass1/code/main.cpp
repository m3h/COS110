/*
 * main function to test code
 */
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include "Wizard.h"
#include "Spell.h"
#include "Hobbit.h"
#include <string>

#define LINER "================================================="

using namespace std;

void printW( Wizard dumbledore )
{
	for(int i = 0; i < dumbledore.getMaxNumberOfSpells(); ++i) {
		if( dumbledore.getSpell(i).getName() != "" )
			cout << dumbledore.getSpell(i) << endl;
	}
	cout << "Lossed" << dumbledore.getNumberOfLossedSpells() << endl;
}


int main() {
	cout << "Testing Hobbit class!" << endl << LINER << endl;
	cout << "Default constructor: creating Hobbit h" << endl;
	Hobbit h;

	cout << "Testing Hobbit setName to \"Frodo\":" << endl;
	h.setName("Frodo");

	cout << "Testing Hobbit getName:" << endl;
	cout << h.getName() << endl;
	cout << "Finished testging Hobbit class!" << endl << LINER << endl << endl;



	cout << "Testing Spell class!" << endl << LINER << endl;
	cout << "Default constructor: creating Spell s" << endl;
	Spell s;

	cout << "Testing setName to Imperio" << endl;
	s.setName("Imperio");

   	cout << "Testing getName" << endl;
	cout << s.getName() << endl;

	cout << "Setting difficulty to 34 and skill level to 2" << endl;
	s.setDifficultyLevel(34);
	s.setSkillLevel(2);

	cout << "Copy constructor: creating SPell s2" << endl;
	Spell s2(s);
	cout << "Printing name of copied thingy" << endl;
	cout << s2.getName() << endl;
	cout << "Changing s2 name to Crucio" << endl;
	s2.setName("Crucio");

	cout << "testing getDifficulty and getSkill" << endl;
	cout << "DifficultyLevel: " << s2.getDifficultyLevel() << endl;
	cout << "SkillLevel: " << s2.getSkillLevel() << endl;

	cout << "Finished testging Spell class!" << endl << LINER << endl << endl;



	cout << "Testing Wizard class!" << endl << LINER << endl;
	cout << "Default constructor: creating Wizard w" << endl;
	Wizard w;

	cout << "Testing addSpell adding s" << endl;
	w.addSpell(s);
	cout << "getNumberOfSpells: " << w.getNumberOfSpells() << endl;
	cout << "getMaxNumberOfSpells() " << w.getMaxNumberOfSpells() << endl;
	cout << "getAge() " << w.getAge() << endl;
	cout << "getNumberOfLossedSpells(): " << w.getNumberOfLossedSpells() << endl;
	cout << "getSpell() ";
	Spell test;
	test = w.getSpell(0);
	cout << test.getName() << endl;

	cout << "testing copy constructor w to dumbledore: " << endl;
	Wizard dumbledore(w);

	cout << "Add spell s2 to dumbledore: " << endl;
	dumbledore.addSpell(s2);

	cout << "setAge to 200 of d" << endl;
	dumbledore.setAge(200);
	cout <<"D.age(): " << dumbledore.getAge() << endl;

	cout << "deleting s from dumbledore" << endl;
	dumbledore.deleteSpell("Imperio");

	cout << "getting spell 0" << endl;
	test = dumbledore.getSpell(0);
	cout << test.getName() << endl;

	cout << "getting spell 1" << endl;
	test = dumbledore.getSpell(1);
	cout << test.getName() << endl;

	cout << "getNumberOfLossedSpells: " << dumbledore.getNumberOfLossedSpells() << endl;

	dumbledore.setMaxNumberOfSpells(3);
	cout << "Set max spells to 3... it is? " << dumbledore.getMaxNumberOfSpells() << endl;

	dumbledore.addSpell(s);
	cout << "Added s. now print 0 again: ";
	test = dumbledore.getSpell(0);
	cout << test.getName() << endl;

	cout << "number of spells: ";
	cout << dumbledore.getNumberOfSpells() << endl;
	dumbledore.addSpell(s);
	dumbledore.addSpell(s);
	cout << "added another two spells: " << endl;

	cout << "number of spells: " << dumbledore.getNumberOfSpells() << endl;

	cout << "setting max to zero" << endl;
	dumbledore.setMaxNumberOfSpells(0);

	cout << "setting max to 1" << endl;
	dumbledore.setMaxNumberOfSpells(1);

	Spell cait("BAZINGA");
	cout << "Adding s2" << endl;
	dumbledore.addSpell(cait);

	cout << "Deleting Crucio" << endl;
	dumbledore.deleteSpell("Crucio");

	cout << "Numbero f lossed spells: " << dumbledore.getNumberOfLossedSpells() << endl;

	cout << "Finished testging Wizard class!" << endl << LINER << endl << endl;
	//
    // commented becaue not implemented...
    // wiz + s1;

    //test your other code here


	cout << "++++++++++++++++++++++++++++" << endl;
	cout << "Test Wizard operator <" << endl;
	cout << "Adding high skill level spell to dumb and low to w" << endl;
	Spell high("HIGH");

	high.setSkillLevel( 6 );
	dumbledore.addSpell( high );

	high.setSkillLevel( 3 );
	w.addSpell( high );

	cout << "dumbelre > w ";
	cout << (dumbledore > w) << endl;

	cout << "w > dumblere ";
	cout << (w > dumbledore) << endl;


	cout << "dumbelre < w ";
	cout << (dumbledore < w) << endl;

	cout << "w < dumblere ";
	cout << (w < dumbledore) << endl;

	cout << "Add Lumos to dumbledore using +" << endl;
	Spell lumos("Lumos");
	dumbledore + lumos;

	cout << "print spells of dumbledore" << endl;
	for(int i = 0; i < dumbledore.getMaxNumberOfSpells(); ++i) {
		if( dumbledore.getSpell(i).getName() != "" )
			cout << dumbledore.getSpell(i).getName() << endl;
	}

	cout << "delete lumos using -" << endl;
	dumbledore - lumos.getName();

	cout << "print spells of dumbledore" << endl;
	for(int i = 0; i < dumbledore.getMaxNumberOfSpells(); ++i) {
		if( dumbledore.getSpell(i).getName() != "" )
			cout << dumbledore.getSpell(i).getName() << endl;
	}

	cout << "Task 3 (35 marks)" << endl;
	Spell spell1, spell2;
	spell2 = spell1;
	cout << (spell2--) << endl;
	cout << (++spell2) << endl;
	cout << (--spell2) << endl;
	cout << (spell2++) << endl;
	spell2 -= 3;
	cout << spell2 << endl;
	cout << "==========================================" << endl;

	cout << "Task 4 (5 Marks)" << endl;

	cout << "hasBeenSummod ()d ";
	cout << h.hasBeenSummoned( dumbledore ) << endl;

	cout << "hasCompletedTraining()d ";
	cout << h.hasCompletedTraining( dumbledore ) << endl;

	cout << "dropWizardSpells()d ";
	h.dropWizardSpells( dumbledore );

	s.setName("hi");
	s2.setName("bye");

	cout << "print spells of w" << endl;
	printW( w );
	cout << "w + s + s2" << endl;
	(w + s) ;
	w + s2;

	cout << "print spells of w" << endl;
	printW( w );
	cout << "-------------------------------" << endl;
	s.setSkillLevel(5);
	cout << endl;
	cout << endl;
	cout << "" <<  s << s2 << endl;
	s2 = ( (s -= 3) -= 4 );
	cout << "" << s << s2 << endl;

	to_string(44);
	for(int i = 0; i < 5; ++i) {
		s.setName(to_string(i) );
		dumbledore + s;
		dumbledore - s.getName();
	}

	Spell tr("Use", 10, 0);	
	Spell tr2("Don't", 23, 0);

	dumbledore + tr;
	dumbledore + tr2;
	dumbledore - s.getName();


	h.dropWizardSpells( dumbledore );
	cout << "DUMBLEDORE! -----------------------------" << endl;
	printW( dumbledore );
	cout << "d summed? " << h.hasBeenSummoned( dumbledore ) << endl;
	cout << endl << " d completed training? " << h.hasCompletedTraining( dumbledore ) << endl;
	cout << "d summed? " << h.hasBeenSummoned( dumbledore ) << endl;

	cout << "Dropping spells" << endl;
	h.dropWizardSpells (dumbledore );

	cout << "DUMBLEDORE! -----------------------------" << endl;
	printW( dumbledore );
	cin.ignore();
    return 0;
}
