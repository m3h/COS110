#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "titleCase.h"
#include "backwards.h"

int main(int argc, char *argv[])
{
	stringstream input;

	if( argc < 2 ) {
		cout << "Error: usage: " << endl << argv[0] << " " << "[STRING HERE]" << endl;
		return 1;
	}

	for(int i = 1; i < argc; ++i) {
		input << argv[i] << " ";
	}

	titleCase tc;
	backwards b;

	cout << tc.print( input.str() ) << endl;
	cout << b.print( input.str() ) << endl;

	return 0;
}
