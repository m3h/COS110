#include <iostream>
#include <string>
#include <cstring>

#include "CharString.h"


#include "CharacterNotFoundException.h"
#include "EmptyException.h"
#include "EmptyResultException.h"
#include "OutOfBoundsException.h"
#include "UnequalSizeException.h"

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
		throw EmptyException();

	size_t totCharSize = numChars+s.numChars-1;
	CharString temp("", 1);

	for(size_t i = 0; i < numChars && characters[i] != '\0'; ++i) {
		temp += characters[i];
	}

	int i;

	for(i = 0; i < s.numChars && s.characters[i] != '\0'; ++i) {
	   temp += s.characters[i];
	}



	return temp;
}

void CharString::operator+= (const CharString &s)
{
	*this = *this + s;
}

CharString CharString::operator- (const char &c)
{
	if(numChars== 0 || numChars == 1)
		throw EmptyException();


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
		//char error[] = "No character \'c\' found!";
		//error[14] = c;

		throw CharacterNotFoundException( c );
	}


	if( j == 0 || j == 1 )
		throw EmptyResultException();

	return temp;
}

void CharString::operator -= (const char &s)
{
	*this = *this - s;
}

CharString CharString::operator* (const CharString &s)
{
	if(s.numChars!= numChars)
		throw UnequalSizeException();
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
		throw EmptyException();

	bool removed = false;

	CharString temp = *this;

	bool pepper;

	size_t i;
	for(i = 0; s.characters[i] != '\0'; ++i) {
		pepper = true;

		try {
			temp -= s.characters[i];
		} catch (EmptyException e) {
			throw e;
		} catch ( CharacterNotFoundException e) {

				pepper = false;

		}

		if( pepper ) {
			removed = true;
		}

	}

	if( !removed )
		throw CharacterNotFoundException();
	if( temp.numChars== 0 || temp.numChars==1)
		throw EmptyResultException();

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
