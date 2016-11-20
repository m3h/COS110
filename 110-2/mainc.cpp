/*
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "Adventurer.h"

// #define DESCRIPTION 0;
// #define WEAPONWEIGHT 1;

//string ***items = new string **[2];

void output(const Adventurer& a);


int main() {
    //add code here to test your class

    // string ***items = new **string[2];

    cout << "Creating Adventurer Herc..." << endl;
    Adventurer herc;
    cout << "Herc created" << endl;
		//cout << "0 " ;
    // give herc values
		//cout << "1 ";

    herc.setName("Hercules");
    //cout << "2 ";
    herc.setHealth(100.0);
    herc.setMaxCarryWeight(25.0);
    herc.setCurrentCarryWeight(0.0);
    herc.setMaxNumberOfItems(10);
    herc.setCurrentNumberOfItems(0);

    string *itt = new string;
    *itt = "Bow";

    herc.pickUpItem("Sword", 5.0);
    herc.pickUpItem("Shield", 4.0);
    herc.pickUpItem(*itt, 2.0);
    herc.pickUpItem("Arrows", 3.0);
    delete itt;
    itt = NULL;
    
    output(herc);

    cout << "Creating Adventurer Finn..." << endl << "Copying Herc to Finn..." << endl;
    Adventurer finn(herc);

    cout << "Finn created!" << endl;

    finn.setName("Finn the Human");
    finn.dropItem("Arrows");
    finn.dropItem(1);

    output(finn);

    cout << "Creating Adventurer Jake..." << endl;
    Adventurer jake;
    cout << "Jake created!" << endl;

    cout << "Copying Finn to Jake..." << endl;
    jake = finn;
    cout << "Finn copied!" << endl;


    jake.setName("Jake the Dog");

    output(jake);

    Adventurer kyle;
    output(kyle);

    output(jake);


    return 0;
}

void output(const Adventurer& a)
{
  string name;
  int numItems;
  int maxItems;
  double carryWeight;
  double maxWeight;
  double health;
  int numAdventurers;

  cout << "\n-------------------------------" << endl;
  name = a.getName();
  maxItems = a.getMaxNumberOfItems();
  carryWeight = a.getCurrentCarryWeight();
  maxWeight = a.getMaxCarryWeight();
  health = a.getHealth();
  numAdventurers = a.getNumberOfAdventurers();
  numItems = a.getCurrentNumberOfItems();
  cout << "Details of Adventurer:" << endl;
  cout << "Name: " << name << endl;
  cout << "Health: " << health << endl;
  cout << "Max carry weight: " << maxWeight << ", Current carry weight: " << carryWeight << endl;
  cout << "Max number of items: " << maxItems << ", Current number of items: " << numItems << endl;
  cout << "Items: " << endl;
  for (int i = 0; i < a.getCurrentNumberOfItems() ; i++)
  {

		string **cait = a.getItem(i);

    cout << *(cait[0]) << endl;
    cout << *(cait[1]) << endl;

	}
  cout << "Number of adventurers: " << numAdventurers;

  cout << "\n-------------------------------" << endl;

}
