#include "Node.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int size;

	if( argc < 1 || argc > 2) {
		cout << "ERROR" << endl;
		return -1;
	} else if (argc == 1) {
		size = 4;
	} else {
		size = atoi(argv[1]);
	}

	string array[size];

	for(int i = 0; i < size; ++i) {
		array[i] = to_string(i);
	}

	Node *one = new Node(size,array);

	cout<<"Original List: "<<endl;

	one->reverse();

	cout<<"Reversed List: "<<endl;

	return 0;
}
