#include <iostream>

using namespace std;

#include "CharString.h"

int main()
{
	CharString a("I am a string", 14);
	CharString b("abdefghjklmng", 14);

	cout << "cout << a << endl;" << endl;
	cout << a << endl << endl;
	
	cout << "cout << b << endl;" << endl;
	cout << b << endl;
	cout << endl;
	
	cout << "cout << a + b << endl;" << endl;
	cout << a + b << endl;
	cout << endl;
	
	CharString T(a);
	T += b;
	cout << "::::T += b" << endl;
	cout << T << endl;
	cout << endl;
	
	cout << "cout << a - 'a' << endl;" << endl;
	cout << a - 'a' << endl;
	cout << endl;
	
	T = a;
	T -= 'a';
	cout << ":::: T -= 'a'" << endl;
	cout << T << endl;
	cout << endl;
	
	cout << "cout << a * b << endl;" << endl;
	cout << a * b << endl;
	cout << endl;
	
	T = a;
	T *= b;
	cout << "::::T *= b" << endl;
	cout << T << endl;
	cout << endl;
	
	cout << "cout << a / b << endl;" << endl;
	try {
		cout << a / b << endl;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	cout << endl;
	
	T = a;
	T /= b;
	cout << "::::T /= b" << endl;
	cout << T << endl << endl;
	
	
	cout << "CharString c(a);" << endl;
	cout << "cout << (c == a) << endl;" << endl;
	CharString c(a);
	cout << (c == a) << endl;
		cout << endl;
	
	cout << "cout << (a == b) << endl;" << endl;
	cout << (a == b) << endl;
		cout << endl;
	
	cout << "cout << a[i] << \"=\" << endl; \\\\ For every element" << endl;
	for( int i = 0; i < a.length(); ++i )
		cout << a[i] << "=";
	cout << endl;
		cout << endl;
	
	cout << "try a[outOfBounds]" << endl;
	try{
		cout << a[-1];
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	cout << endl;
	
	cout << "::::a + empty" << endl;
	CharString em;
	try {
		a + em;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout << "::::a - notFoundC" << endl;
	try {
		a - '1';
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout <<"::::empty - 'c'" << endl;
	try {
		em - 'c';
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	CharString cc("ccccc", 6);
	cout << "::::onlyOneC - OneC" << endl;
	try {
		cc - 'c';
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout << "::::Csize1 * Csize2" << endl;
	try {
		cc * a;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout << "::::a / notFoundCS" << endl;
	try {
		cout << (a  / cc) << endl; ;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout <<"::::empty / a" << endl;
	try {
		em / a;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	CharString ca("cacaca", 7);
	CharString dell("ca", 3);
	cout << "::::onlyTwoC / TwoC" << endl;
	try {
		cc / dell;
	} catch (Exception e) {
		cout << e.what() << endl;
	}
	
	cout << "::::onlyTwoC /= TwoC" << endl;
	try {
		cc /= dell;
	} catch (Exception e) {
		cout << e.what() << endl;
	}

	CharString aaa("aaa", 4);
	CharString bbb("bbb", 4);

	aaa += bbb;
	cout << aaa << endl;
	for(int i = 0; i < aaa.length(); ++i) {
		cout << "[" << aaa[i] << "]" << endl;
	}
}
