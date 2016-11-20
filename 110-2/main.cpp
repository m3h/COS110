/*
 * Add comments here
 */
#include <iostream>
#include <string>

using namespace std;
#include "Adventurer.h"

int main() {
    //add code here to test your class
    Adventurer reece;
	
    if( reece.pickUpItem( "hammer", 12) ) {
      cout << "Picked up hammer!\n";
    } else {
      cout << "Did not pick up hammer\n";
    }
    if( reece.pickUpItem( "car", 200) ) {
      cout << "Picked up car!\n";
    } else {
      cout << "Did not pick up car!\n";
    }
    if( reece.pickUpItem( "gun", 5) ) {
      cout << "Picked up gun!\n";
    } else {
      cout << "Did not pick up gun!\n";
    }
    if( reece.pickUpItem( "thing", 20) ) {
      cout << "Picked up thing!\n";
    } else {
      cout << "Did not pick up thing!\n";
    }

    if( reece.pickUpItem( "jackknife", 10) ) {
      cout << "Picked up jackknife!\n";
    } else {
      cout << "Did not pick up jacknife!\n";
    }

    if( reece.dropItem( "gun" ) ) {
      cout << "Dropped gun!\n";
    } else {
      cout << "Did not Drop gun!\n";
    }

    if( reece.dropItem( 1 ) ) {
      cout << "Dropped item 1!\n";
    } else {
      cout << "Did not drop 1\n";
    }

    reece.setName("Reece");
    cout << reece.getName() << endl;

    reece.setMaxCarryWeight(300.0);
    cout << reece.getMaxCarryWeight() << endl;

    cout << "Current Carry Weight: " << reece.getCurrentCarryWeight() << endl;
    reece.setCurrentCarryWeight(222.0);
    cout << reece.getCurrentCarryWeight() << endl;
    
	reece.setMaxNumberOfItems(12);
    cout << reece.getMaxNumberOfItems() << endl;

    //reece.setCurrentNumberOfItems( 5 );
    //cout << reece.getCurrentNumberOfItems() << endl;
	
	Adventurer john(reece);
    cout << "adventurers" << reece.getNumberOfAdventurers() << endl;

    reece.setHealth( 200.0 );
    cout << reece.getHealth() << endl;

	reece.pickUpItem( "cait", 49.5 );
	reece.pickUpItem( "phone", 0.5 );

	Adventurer test;
	test.setName("I am a test");
	test.pickUpItem("BIG HAMMER", 23.5);

	cout << test.getCurrentNumberOfItems() << endl;
	test = reece;

	test.pickUpItem("BIG HAMMER", 23.5);
	reece =test;

	cout << "========================" << endl;
	cout << reece.getName() << " ITEMS: " << reece.getCurrentNumberOfItems() << endl;
	cout << "========================" << endl;

	for(int i = 0; i < reece.getCurrentNumberOfItems(); i++) {
		string **stringer = reece.getItem(i);

		cout << "Name:   " << *(stringer[0]) << endl;
		cout << "Weight: " << *(stringer[1]) << endl;
	}
    return 0;
}
