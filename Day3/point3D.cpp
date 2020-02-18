#include "Point3D.h"

#include <iostream>
using namespace std;

Point3D::Point3D(int nx, int ny, int nz) : Point(nx,ny), z(nz)
{
	//z = nz; // Another option for z
}

int Point3D::getZ() {
	return z;
}

void Point3D::print() {

	// x and y are private in the base class or we could have
	// used them directly here. Better to program to the 
	// interface anyway.

	cout << "Point " << getX() << "," << getY() << "," << z << endl;
}