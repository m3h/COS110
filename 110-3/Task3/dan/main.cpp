#include <iostream>
#include <string>

using namespace std;

#include "library.h"
#include "book.h"
#include "librarian.h"

int main( int argc, char **argv )
{
  Library t("Texas");
  Book *hp = new Book( "Harry Potter 1", "J.K Rownling", "1234567890" );

  Library b( t );
  b.setName("Balclutha");
  
  Book *newa = new Book("New book", "John", "122223" );

  t.print();
  b.print();

  Librarian c( t, "Cathy");
  c.returnBook( hp );
  t.print();
  
  delete hp;
  hp = NULL;
  delete newa;
  newa = NULL; 

  return 0;
}
