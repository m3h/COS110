#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string array1[]  = {"g","f","h","d","b","ac"};
	LinkedList *one = new LinkedList(6,array1);

	string array2[]  = {"e","j","i","l","k","ab"};
	LinkedList *two = new LinkedList(6,array2);

	string array3[]  = {};
	LinkedList *three = new LinkedList(0,array3);
	
	LinkedList *answer;	


	//answer = one->combine(two);

	//if(answer)
	//	answer->display();

	
	answer = three->combine(one);

	if(answer)
		answer->display();

	return 0;
}

/* Expected output

a b c d e f g h i j k l 

*/