#include "Span.hpp"
#include <algorithm>
#include <ctime>

int main()
{
	std::srand(unsigned(std::time(nullptr)));
	std::vector<int> v(100);
	std::generate(v.begin(), v.end(), std::rand);

	//Span sp(8);
	Span sp = Span(v.begin(), v.end());
	std::cout << "PASA" << std::endl;
	try {

		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		// sp.addNumber(90);
		// sp.addNumber(111);
		// sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}