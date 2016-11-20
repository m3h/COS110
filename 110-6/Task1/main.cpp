#include <iostream>

#include "cuboid.h"

using namespace std;
int main()
{
	Cuboid<int> i(12,13,14);

	Cuboid<double> d(12.4, 13.4, 14.5);

	cout << i.getVolume() << " " << i.getSurfaceArea() << endl;

	cout << d.getVolume() << " " << d.getSurfaceArea() << endl;


}
