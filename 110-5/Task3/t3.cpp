#include <iostream>


using namespace std;

#include "EmptyException.h"

int main()
{
	try {
		throw EmptyException();
	} catch (Exception e) {
		cout << e.what() << endl;
	}
}
