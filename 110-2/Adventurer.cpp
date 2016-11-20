
//Implement or define your class here
// Adventurer class implementation,
//		Reece Volker, 8/16/2016
#include "Adventurer.h"

#include <sstream>
#include <memory>
#include <iostream>

#define DESCRIPTION 0
#define ITEMWEIGHT 1


int Adventurer::numberOfAdventurers = 0;

Adventurer::Adventurer()
{
	numberOfAdventurers++;

	name = "Adventurer";
	maxCarryWeight = 100.0;
	currentCarryWeight = 0.0;
	maxNumberOfItems = 3;
	currentNumberOfItems = 0;
	health = 100.0;

	items = new string **[maxNumberOfItems];
	for(int i = 0; i < maxNumberOfItems; i++) {
		items[i] = new string *[2];
	}
}

Adventurer::Adventurer(const Adventurer& a)
{
	++numberOfAdventurers;

	//for( int i = 0; i < maxNumberOfItems; i++ ) {
	//	delete [] items[i];
	//}
	//delete [] items;
	//items = NULL;

	items = new string **[a.getMaxNumberOfItems()];

	for(int i = 0; i < a.getMaxNumberOfItems(); i++) {
		items[i] = new string *[2];
	}

	for(int i = 0; i < a.getCurrentNumberOfItems(); i++) {
		string **tempItem = a.getItem(i);

		items[i][DESCRIPTION] = tempItem[DESCRIPTION];
		items[i][ITEMWEIGHT] = tempItem[ITEMWEIGHT];
		//items[i][DESCRIPTION] = a.items[i][DESCRIPTION];
		//items[i][ITEMWEIGHT] = a.items[i][ITEMWEIGHT];
	}

	name = a.getName();
	maxCarryWeight = a.getMaxCarryWeight();
	currentCarryWeight = a.getCurrentCarryWeight();
	currentNumberOfItems = a.getCurrentNumberOfItems();
	maxNumberOfItems = a.getMaxNumberOfItems();
	health = a.getHealth();
}

Adventurer::~Adventurer()
{
	for(int i = 0; i < maxNumberOfItems; i++) {
		delete [] items[i];
	}
	delete [] items;
	items = NULL;

	--numberOfAdventurers;
	// cout << "Destructed " << name << " " << numberOfAdventurers << endl;
}

bool Adventurer::pickUpItem(string it, double weight)
{
	if( (currentNumberOfItems >= maxNumberOfItems) || (currentCarryWeight+weight>maxCarryWeight)) {
		return false;
	}

	items[currentNumberOfItems][DESCRIPTION] = &it;

	stringstream ss;
	ss << weight;
	string weightString = ss.str();

	string *sptr = new string;

	*sptr = ss.str();
	items[currentNumberOfItems][ITEMWEIGHT] = sptr;

	++currentNumberOfItems;
	currentCarryWeight += weight;

	return true;
}

bool Adventurer::dropItem(string it)
{
	int itemIndex = -1;

	for(int i = 0; i < currentNumberOfItems; i++) {
		if( *(items[i][DESCRIPTION]) == it) {
			itemIndex = i;
			break;
		}
	}

	if(itemIndex == -1) {
		return false;
	} else {

		dropItem(itemIndex);
		return true;

	}

}

bool Adventurer::dropItem(int index)
{
	if( index >= currentNumberOfItems ) {
		return false;
	}

	currentCarryWeight -= atof( (*(items[index][ITEMWEIGHT])).c_str() );
	--currentNumberOfItems;

	delete items[index][ITEMWEIGHT];
	items[index][ITEMWEIGHT] = nullptr;

	for(int i = index; i < currentNumberOfItems; i++) {
		items[i][DESCRIPTION] = items[i+1][DESCRIPTION];
		items[i][ITEMWEIGHT] = items[i+1][ITEMWEIGHT];
	}

	return true;
}

void Adventurer::setName(string n)
{
	name = n;
}

string Adventurer::getName() const
{
	return name;
}

void Adventurer::setMaxCarryWeight(double w)
{
	maxCarryWeight = w;
}

double Adventurer::getMaxCarryWeight() const
{
	return maxCarryWeight;
}

void Adventurer::setCurrentCarryWeight(double w)
{
	currentCarryWeight = w;
}

double Adventurer::getCurrentCarryWeight() const
{
	return currentCarryWeight;
}

void Adventurer::setMaxNumberOfItems(int n)
{
	string *temp[200][2];

	for(int i = 0; i < currentNumberOfItems && i < n; i++) {
		temp[i][DESCRIPTION] = items[i][DESCRIPTION];
		temp[i][ITEMWEIGHT] = items[i][ITEMWEIGHT];
	}
	for(int i = 0; i < maxNumberOfItems; i++) {
		delete [] items[i];
	}
	delete [] items;
	items = NULL;

	items = new string **[n];
	for(int i = 0; i < n; i++) {
		items[i] = new string *[2];
	}

	for(int i = 0; i < currentNumberOfItems; i++) {
		items[i][DESCRIPTION] = temp[i][DESCRIPTION];
		items[i][ITEMWEIGHT] = temp[i][ITEMWEIGHT];
	}
	maxNumberOfItems = n;
}

int Adventurer::getMaxNumberOfItems() const
{
	return maxNumberOfItems;
}

void Adventurer::setCurrentNumberOfItems(int n)
{
	currentNumberOfItems = n;
}

int Adventurer::getCurrentNumberOfItems() const
{
	return currentNumberOfItems;
}

int Adventurer::getNumberOfAdventurers() const
{
	return numberOfAdventurers;
}

void Adventurer::setHealth(double h)
{
	health = h;
}

double Adventurer::getHealth() const
{
	return health;
}

string** Adventurer::getItem(int index) const
{
	return items[index];
}

Adventurer& Adventurer::operator = (const Adventurer& a)
{

	if(&a == this )
		return *this;

    // delete items array of this
	for(int i = 0; i < maxNumberOfItems; i++) {
		delete [] items[i];
	}
	delete [] items;
	items = NULL;

    // allocate items array
	items = new string **[a.getMaxNumberOfItems()];

	for(int i = 0; i < a.getMaxNumberOfItems(); i++) {
		items[i] = new string *[2];
	}

    // assign items array
	for(int i = 0; i < a.getCurrentNumberOfItems(); i++) {
		string **tempItem = a.getItem(i);

		items[i][DESCRIPTION] = tempItem[DESCRIPTION];
		items[i][ITEMWEIGHT] = tempItem[ITEMWEIGHT];
	}

    // assign other variables
	name = a.getName();
	maxCarryWeight = a.getMaxCarryWeight();
	currentCarryWeight = a.getCurrentCarryWeight();
	currentNumberOfItems = a.getCurrentNumberOfItems();
	maxNumberOfItems = a.getMaxNumberOfItems();
	health = a.getHealth();

	return *this;
}
