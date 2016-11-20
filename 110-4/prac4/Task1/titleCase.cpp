#include <iostream>
#include <string>
#include <sstream>


using namespace std;

#include "titleCase.h"

string titleCase::strToTitle( string s )
{
	stringstream ss(s);
	stringstream out;
	string tempWord;

	while( ss >> tempWord)	{	// work word by word

		int i;
		for(i = 0; i < tempWord.length(); ++i)	// make word lowercasse {
			tempWord[i] = tolower(tempWord[i]);

		if( tempWord != "and" && tempWord != "the" && tempWord != "a" ) // must capitlaise first letter`j
			tempWord[0] = toupper(tempWord[0]);

		out << tempWord << " ";
	}

	return out.str(); 
} 


string titleCase::print( string s )
{
	string titled = strToTitle( s );

	return titled;
}
