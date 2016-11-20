#include <iostream>

using namespace std;

void reallocShort3d(short ***&ptr, size_t oldSize, size_t newSize)
{
	short ***temp = new short **[newSize];
	
	for( size_t i = 0; i < oldSize; i++ ) {
		temp[i] = ptr[i];
	}
	
	
	ptr = temp;
	
	return;
}

int main()
{
	short ***ptr = new short **[3];
	short **ptr2;

	ptr[0] = ptr2;

	reallocShort3d(ptr, 3, 20);
	ptr[100] = ptr2;
	cout << ptr[0] << ptr[100] << endl;


	cout << sizeof(ptr) << endl;

	return 0;
}
