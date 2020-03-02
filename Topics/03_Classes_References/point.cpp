#include "Point.h"

#include <iostream>
using namespace std;

Point::Point() : x(0), y(0) { 
	//x=0;  // Initializer list is mandatory for initing base class.
	//y=0;  // Shown here for demonstration.
}

Point::Point(int nx, int ny) {
	x = nx;
	y = ny;
}

Point::~Point() {
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::print() {
	cout << "Point " << x << "," << y << endl;
}