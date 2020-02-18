#ifndef _line_h_
#define _line_h_

#include "point.h" // Using the "Point" type in functions

namespace topher {

	class Line {

	private:

		// NEVER us a "using" in an include file. If you do the module that includes you will
		// have to put up with it with no way around it.

		topher::Point a;  // Spell out "Point" with its namespace
		topher::Point b;

	public:

		// Two "overloaded" constructors here. Two different ways to make a line.
		Line(int x1, int y1, int x2, int y2);
		Line(topher::Point a, topher::Point b);

		// These are return-by-value ... not pointers. Caller gets a copy
		Point getPointA();
		Point getPointB();

		float getLength();

	};

}

#endif
