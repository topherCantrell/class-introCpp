#ifndef POINT_H_  // "POINT_H_" is up to you. Pick something unique.
#define POINT_H_

class Point {
	              // Private by default
	int x;
	int y;

public:           // Public interface for people to use

	Point();               // "No-args" constructor
	Point(int nx, int ny); // Constructor with arguments

	~Point();              // Destructor

	// Could (should) make these "inline".
	int getX();
	int getY();

	void print();

}; // Don't forget the semicolon

#endif