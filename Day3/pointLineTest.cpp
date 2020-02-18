#include <iostream>
using namespace std;

#include "line.h"
#include "point.h"
#include "point3D.h"

using namespace topher;

int main() {

	// Create a point at 1,1
	Point p(1,1);
	cout << "Square root of two is " << p.getDistanceFromOrigin() << endl;

	// Change the point to 3,4
	p.setXY(3,4);
	cout << "New magnitude is " << p.getDistanceFromOrigin() << endl;

	// Make a line from 0,0 to 1,1
	Line a(0,0,1,1);
	cout << "Length is " << a.getLength() << endl;

	// Make a line using Point constructor
	// If defining the Points in the argument list confuses you then break them
	// out to temporaries before.
	Line b(Point(2,5),Point(10,11));
	cout << "Length is " << b.getLength() << endl;

	// Note that we access "getX" and "getY" even though Point3D doesn't have them. It picks them
	// up through inheritance.
	Point3D threeD(1,2,3);
	cout << "X:" << threeD.getX() << "  Y:" << threeD.getY() << "  Z:" << threeD.getZ() << endl;

}