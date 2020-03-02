
#include "line.h"
#include "math.h"

namespace topher {


	Line::Line(int x1, int y1, int x2, int y2) : a(x1,y1), b(x2,y2)
	{
	}

	Line::Line(topher::Point ia, topher::Point ib) : a(ia), b(ib)
	{
	}

	topher::Point Line::getPointA()
	{
		return a;
	}

	topher::Point Line::getPointB()
	{
		return b;
	}

	float Line::getLength()
	{
		float x = b.getX() - a.getX();
		float y = b.getY() - a.getY();
		return sqrt(x*x + y*y);
	}

}