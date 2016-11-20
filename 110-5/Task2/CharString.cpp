#include <iostream>
#include <string>
#include <cstring>

#include "CharString.h"

CharString::CharString()
{
	numChars = 1;

	characters = new char[numChars];
	characters[0] = '\0';
}

CharString::CharString(const char *in, int inSize)
{
	numChars = inSize;

	characters = new char[inSize];
	for(size_t i = 0; i < inSize; ++i) {
		characters[i] = in[i];
	}
}

CharString::CharString(const CharString& s)
{
	numChars = s.numChars;
	characters = new char[numChars];
	for(size_t i = 0; i < numChars; ++i) {
		characters[i] = s.characters[i];
	}
}

CharString::~CharString()
{
	delete [] characters;
}

void CharString::reallocateArray(int newSize)
{
	char *newC = new char[newSize];
	for(size_t i = 0; i < numChars && i < newSize; ++i) {
		newC[i] = characters[i];
	}

	delete [] characters;
	characters = newC;
}

CharString CharString::operator+ (const char &c)
{
	if( c == '\0' )
		return *this;

	char tempC[numChars+1];

	for(size_t i = 0; i < numChars; ++i) {
		tempC[i] = characters[i];
	}

	size_t j;
	if( numChars > 0 )
		j = numChars;
	else
		j = 1;

	tempC[j-1] = c;
	tempC[j] = '\0';

	CharString job(tempC, j+1);
	return job;

}

CharString CharString::operator+= (const char &c)
{
	*this = *this + c;

	return *this;
}

const CharString CharString::operator= (const CharString &s)
{
	delete [] characters;

	numChars= s.numChars;
	characters = new char[numChars];

	for(size_t i = 0; i < numChars; ++i) {
		characters[i] = s.characters[i];
	}

	return *this;
}

CharString CharString::operator+ (const CharString &s)
{
	if( s.numChars== 0 || s.numChars == 1)
		throw Exception("The string is empty!");

	size_t totCharSize = numChars+s.numChars-1;
	CharString temp("", 1);

	for(size_t i = 0; i < numChars && characters[i] != '\0'; ++i) {
		temp += characters[i];
	}

	for(size_t i = 0; i < s.numChars; ++i) {
	   temp += s.characters[i];
	}
	//cout << "totCharSize: " << totCharSize << endl;
	//cout << "strlen: " << strlen(temp) << endl;

	return temp;
}

void CharString::operator+= (const CharString &s)
{
	*this = *this + s;
}

CharString CharString::operator- (const char &c)
{
	if(numChars== 0 || numChars == 1)
		throw Exception("The string is empty!");


	char stripped[numChars];

	bool found = false;

	size_t j = 0;
	for(size_t i = 0; i < numChars; ++i) {
		if( characters[i] == c )
			found = true;
		else {
			stripped[j++] = characters[i];
		}

	}

	CharString temp(stripped, j);

	if(found == false) {
		char error[] = "No character \'c\' found!";
		error[14] = c;

		throw Exception( error );
	}


	if( j == 0 || j == 1 )
		throw Exception("The result is an empty string!");

	return temp;
}

void CharString::operator -= (const char &s)
{
	*this = *this - s;
}

CharString CharString::operator* (const CharString &s)
{
	if(s.numChars!= numChars)
		throw Exception("Strings are unequal lengths!");
	if(numChars == 1) {
		CharString em("", 1);
		return em;
	}

	CharString temp;
//	char temp[numChars*2];

	size_t j = 0;

	for(size_t i = 0; i < numChars*2; ++i) {
		if(i%2 == 0)
			temp += characters[j];
		else
			temp += s.characters[j++];
	}

	//CharString ret(temp, numChars*2);

	return temp;
}

void CharString::operator*= (const CharString &s)
{
	*this = *this * s;
}

CharString CharString::operator/ (const CharString &s)
{
	if( numChars== 0 || s.numChars== 0 || numChars == 1 || s.numChars == 1 )
		throw Exception("The string is empty!");

	bool removed = false;

	CharString temp = *this;

	bool pepper;

	size_t i;
	for(i = 0; s.characters[i] != '\0'; ++i) {
		pepper = true;

		try {
			temp -= s.characters[i];
		} catch (Exception e) {
			if( e.what() == "The result is an empty string!" )
				throw e;
			else
				pepper = false;

		}

		if( pepper ) {
			removed = true;
		}

	}

	if( !removed )
		throw Exception("No character found!");
	if( temp.numChars== 0 )
		throw Exception("The result is an empty string!");

	return temp;
}

void CharString::operator/= (const CharString &s)
{
	*this = *this / s;
}

bool CharString::operator == (const CharString &s )
{
	if( numChars!= s.numChars)
		return false;

	for(size_t i = 0; i < numChars; ++i ) {
		if( characters[i] != s.characters[i] )
			return false;
	}

	return true;
}

char &CharString::operator[] (int i) const
{
	if(i > numChars-1 || i < 0)
		throw Exception("Index out of bounds!");

	return characters[i];
}

ostream &operator << (ostream &os, const CharString &s)
{
	os << s.characters;

	return os;
}

const int CharString::length() const
{
	return numChars;
}
