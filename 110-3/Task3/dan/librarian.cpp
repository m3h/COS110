#include <iostream>
#include <string>

#include "library.h"
#include "book.h"
#include "librarian.h"

using namespace std;

Librarian::Librarian( Library &libIn, string nameIn ): lib(libIn), name(nameIn)
{
}

Book* Librarian::lendBook( string bname )
{
	if(lib
}

void returnBook(Book *book)
{
	if( lib.isFull() ) {
		lib++;
	}

	lib += lent;

	cout << "name" << ": Thanks for returning " << lent->getTitle() << "!" << endl;

	return;
}
