
#include <iostream>
using namespace std;

class Point {

	int x;
	int y;

public:

	Point(int x, int y) {
		cout << "In constructor" << endl;
		this->x = x;
		this->y = y;
	}

	~Point() {
		cout << "In destructor" << endl;
	}

	int getX() {return x;}
	int getY() {return y;}


};

int main() {

	Point * q = new Point(3,4);
	delete q;

	Point * oops = new Point(5,6);

	Point p = Point(1,2);

}


