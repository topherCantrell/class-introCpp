#ifndef POINT3D_H_
#define POINT3D_H_

#include "Point.h"

class Point3D : public Point { // Public inheritance

	int z;

public:

	Point3D(int nx, int ny, int nz);

	inline int getZ(); // "inline" added here for demonstration

	void print();

};

#endif