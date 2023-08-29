#include "whatever.hpp"

int main ()
{
	int a = 1;
	int b = 2;
	std::cout << "a = " << a << " b = " << b << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min(a,b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a,b) = " << ::max(a, b) << std::endl;


	std::string c = "hola";
	std::string d = "adios";
	std::cout << "c = " << c << " d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min(c,d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c,d) = " << ::max(c, d) << std::endl;

	return (0);
}