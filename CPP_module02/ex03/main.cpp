#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	{
	const Point a(-8, 7);
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(3, 5);

	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
}