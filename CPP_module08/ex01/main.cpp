#include "Span.hpp"
#include <algorithm>
#include <ctime>

int main()
{
	std::srand(unsigned(std::time(nullptr)));
	std::vector<int> v(1000);
	std::generate(v.begin(), v.end(), std::rand);

	Span sp(8);
	try {

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(30);
		sp.addNumber(17);
		sp.addNumber(90);
		sp.addNumber(11);
		sp.addNumber(9);
		sp.addNumber(111);
		// sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}

	std::cout << std::endl << "WITH RANDOM VECTOR" << std::endl << std::endl;
	Span rdm_sp(1000);
	try {
		rdm_sp.addNumber(v.begin(), v.end());
		std::cout << rdm_sp.shortestSpan() << std::endl;
		std::cout << rdm_sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}