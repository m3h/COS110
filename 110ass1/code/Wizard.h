/*
 * Class Wizard
 */

#ifndef WIZARD_H
#define	WIZARD_H

#include "Spell.h"

class Wizard{

private:
    Spell* spells;
    int numberOfSpells;
    int maxNumberOfSpells;
    bool hasBeenSummoned;
    int age;
    int numberOfLossedSpells;
    bool hasCompletedTraining;
    void initialiseSpells( Spell *spells, int m);

public:
    Wizard();
    Wizard(const Wizard& w);
    ~Wizard();
    void addSpell(const Spell& s);
    void deleteSpell(string name);
    int getNumberOfSpells() const;
    void setMaxNumberOfSpells(int m);
    int getMaxNumberOfSpells() const;
    void setAge(int a);
    int getAge() const;
    int getNumberOfLossedSpells() const;
    void setNumberOfLossedSpells(int num=0);
    Spell& getSpell(int index) const;
  	bool getHasCompletedTraining() const;
    void setHasCompletedTraining(bool b=true);
  	bool getHasBeenSummoned() const;
    void setHasBeenSummoned(bool b=true);

  	// Task 2
  	bool operator > (const Wizard &wiz2 ) const;
  	bool operator < (const Wizard &wiz2 ) const;

  	void operator + (const Spell& spell);
  	void operator - (const string spellName);

    friend class Hobbit;
};

#endif	/* WIZARD_H */
