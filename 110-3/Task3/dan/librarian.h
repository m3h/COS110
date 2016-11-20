#ifndef LIBRIAN_H
#define LIBRIAN_H

#include <iostream>
#include <string>

#include "library.h"
#include "book.h"

class Librarian
{
	private:
		Library &lib;
		const string name;

	public:
		Librarian( Library &a, const string n);
		Book* lendBook( string );
		void returnBook( Book* );
};
#endif
