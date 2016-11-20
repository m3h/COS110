#include <iostream>
#include <string>
#include <sstream>


using namespace std;

#include "backwards.h"

string backwards::strBackwards( string s )
{
	stringstream ss(s);
	stringstream out;
	string tempWord;

	while( ss >> tempWord)	{	// work word by word

		string revWords("");

		for(int i = 0; i < tempWord.length(); ++i) {
			revWords += tempWord[tempWord.length() - 1 - i];	// first rev C gets last temo C
		}


		out << revWords << " ";
	}

	return out.str(); 

} string backwards::print( string s )
{
	string back = strBackwards( s );

	return back;
}
