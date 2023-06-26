#include "Point.hpp"
#include "Fixed.hpp"

static float area (const Point p1, const Point p2, const Point p3)
{
	float area;

	// AREA = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))/2

	area = ((p1.get_x().toFloat() * ((p2.get_y().toFloat()) - p3.get_y().toFloat())) + p2.get_x().toFloat() * (p3.get_y().toFloat() - p1.get_y().toFloat())
	 + p3.get_x().toFloat() *  (p1.get_y().toFloat() - p2.get_y().toFloat())) / 2;

	if (area < 0)
		return (area * -1);
	return (area);
}

bool bsp(const Point a, const Point b,const Point c, const Point point)
{
	float a1, a2, a3, a4;
	bool status = false;

	a1 = area(a, b, c);
	a2 = area(point, a, b);
	a3 = area(point, b, c);
	a4 = area(point, a, c);

	if (a2 == 0 || a3 == 0 || a4 == 0)
		status = false;
	else if (a2 + a3 + a4 == a1)
		status = true;
	return (status);
}