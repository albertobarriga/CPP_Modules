#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():_x(0), _y(0) {
}

Point::Point(const float x, const float y):_x(x), _y(y) {
}

Point::Point(const Point &copy): _x(copy.get_x()), _y(copy.get_y()) {
}

Point::~Point() {
}

Point &Point::operator=(const Point &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

Fixed Point::get_x(void) const {
	return (this->_x);
}

Fixed Point::get_y(void) const {
	return (this->_y);
}
