#ifndef CUBOID_H
#define CUBOID_H

template <class T>
class Cuboid {

	private:
		T x, y, z;

	public:
		Cuboid( T a, T b, T c ) { x = a; y = b; z = c; }

		T getVolume() { return x*y*z; }
		T getSurfaceArea() { return 2*(x*y + x*z + y*z); }
};

#endif
