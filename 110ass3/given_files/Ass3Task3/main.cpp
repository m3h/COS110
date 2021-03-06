#include <iostream>
#include "doubleList.h"

using namespace std;

int main()
{
  //Write code to test your implementation.
  
	
	DoubleList<char> list1;
	char value = 'a';
	
	cout << "-----------insert------------" << endl;
	try {
		list1.insert(-1, 'z');
		cout << list1 << endl;
	}
	catch (const char *s) {
		cout << s << endl;
	}
	
	
	try{
		list1.insert(0,value);
		value++;
		cout << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	try {
		list1.insert(2, 'z');
		cout << list1 << endl;
	}
	catch (const char *s) {
		cout << s << endl;
	}
	cout << "-----copy constructor---------------" << endl;
	
	DoubleList<char> empty;
	DoubleList<char>* list2 = new DoubleList<char>(empty);
	cout << *list2 << endl;
	delete list2;
	list2 = new DoubleList<char>(list1);
	//cin.ignore();
	empty = *list2;
	//cout << empty << endl;

	empty.insert(1, 'z');
			//cin.ignore();

	empty.insert(0, 'z');
	DoubleList<char> zz(empty);
	cout << empty << endl;;

	cout << *list2 << endl;

	cout << "-----------get------------" << endl;

	list1.insert(0, 'z');
	list1.insert(1, 'x');
	for(int i = -1; i < 4; ++i) {
		try{
			cout << i << ":: index: " << i << list1.get(i) << list1 << endl;
			
		}
		catch (const char * s){
			cout << i << " ERROR: " << s << endl;
		}
	}
	try {
		empty.clear();
		cout << "Empty:: " << empty.get(8) << empty << endl;
	} catch (const char* s) {
		cout << "Error on empty:: " << s << endl;
	}
	
	cout << "-----------operator[]------------" << endl;
	//cout << list1 << endl;
	for(int i = -1; i < 4; ++i) {
	try{
		cout << "index: " << i << list1[i] << endl;
		
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
}

	try {
		empty.clear();
		cout << "Empty:: " << empty[2] << empty << endl;
	} catch (const char* s) {
		cout << "Error on empty:: " << s << endl;
	}
	
	cout << "-----------remove------------" << endl;
	try{
		
		cout << list1.remove(-1) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	try{
		
		cout << list1.remove(10) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	try{
		
		cout << list1.remove(1) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	try{
		
		cout << list1.remove(0) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
		try{
		
		cout << list1.remove(0) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	try{
		
		cout << list1.remove(0) << " -> " << list1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----------operator=------------" << endl;
	list1 = *list2;
	
	cout << list1 << endl;
	DoubleList<char> dd;
	dd = empty;
	cout << empty << endl;
	
	cout << "-----------operator+------------" << endl;
	
	for(char c = 'a'; c < 'f'; ++c)
		list1.insert(0, c);
	
	list2->insert(0, 'z');
	cout << list1 << " " << *list2 << endl;
	DoubleList<char> list3 = list1 + *list2;
	
	cout << list3 << endl;
	cout << list3 + list3 << endl;
	cout << list3 + empty << endl;
	cout << empty + list3 << endl;
	
  return 0;
  /////////////////////////////////////////////////////////
}
