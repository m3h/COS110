#include <iostream>
#include "linkedList.h"

using namespace std;

int main()
{
  //Write code to test your implementation.
  
	
	LinkedList<char> list1;
	char value = 'a';
	
	cout << "-----------insert------------" << endl;
	try{

		for(int i = 0; i < 10; i++) {
			list1.insert(i,value++);
		}
		value = '1';
		for(int i = 0; i < 10; i += 2) {
			list1.insert(i, value++);
		}
		list1.insert(15, 'd');
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	cout << list1 << endl;
	cout << "-----copy constructor---------------" << endl;
	
	LinkedList<char>* list2 = new LinkedList<char>(list1);
	cout << *list2 << endl;
	cout << "-----------get------------" << endl;

	for(int i = -1; i < 17; i++)
	try{
		
			cout << "index: " << i << " " << list1.get(i) << list1 << endl;
		
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----------operator[]------------" << endl;
	//cout << list1 << endl;
	try{
		cout << "index: 2" << list1[16] << endl;
		
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----------remove------------" << endl;
	for(int i = 17; i > -2; i--)
	try{
		
		cout << list1.remove(0) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----------operator=------------" << endl;
	list1 = *list2;
	
	cout << list1 << endl;
	
	cout << "-----------operator+------------" << endl;
	
	LinkedList<char> list3 = list1 + *list2;
	
	cout << list3 << endl;
  return 0;
  /////////////////////////////////////////////////////////
}
