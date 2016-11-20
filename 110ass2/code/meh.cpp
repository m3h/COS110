#include <iostream>
#include <string>

#include "ZigZag.h"
#include "CipherPipeline.h"
#include "Caesar.h"
#include "OneTimePad.h"

using namespace std;

int main()
{

	string plaint = "Hello, World!..";

	ZigZag zz;

	cout << plaint << endl;
	plaint = zz.encode(plaint);
	cout << plaint << endl;
	plaint = zz.decode(plaint);
	cout << plaint << endl;

	cout << "Now CP" << endl;
	CipherPipeline cp;
	ZigZag *z1 = new ZigZag;
	Caesar *c1 = new Caesar;
	c1->setShift(33);
	OneTimePad *otp = new OneTimePad(66667);


	cp += z1;
	cp += c1;
	cp += z1;
	cp += c1;
	cp += otp;
	for(int i = 0; i < 1000; ++i) {
		cp += otp;
		cp += z1;
		cp += c1;
	}

	string plainer = "I love you, Cait";

	cout << plainer << endl << endl;
	plainer = cp.encode(plainer);
	cout << plainer << endl << endl;


	plainer = cp.decode(plainer);
	cout << plainer << endl << endl;

	cp = *z1 + *c1;
	plainer = cp.encode(plainer);
	cout << plainer << endl << endl;
	plainer = cp.decode(plainer);
	cout << plainer << endl << endl;

	delete z1;
	delete c1;
	delete otp;
	/*
    string plaint = "{{ Hello World! }}";

    Caesar dude;

	std::cout << "testing Caesar encode! Enter shift:" << std::endl;
	std::string splaint = dude.encode( plaint );
    cout << splaint << endl;

    cout << dude.decode( splaint ) << endl;

	OneTimePad pants( 1 );

	int in;
	std::string temp;

	cout << "Testing OneTimePad! Enter seed (-1 for quit)" << std::endl;
	do {
		cin >> in;
		pants.setSeed( in );

		temp = pants.encode( plaint );
		cout << temp << endl;

		temp = pants.decode( temp );
		cout << temp << endl;
	} while (in != -1);
*/
}
