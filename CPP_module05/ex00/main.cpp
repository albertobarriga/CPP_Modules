#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat one("PACO", 155);
		std::cout << one;
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}

	Bureaucrat two("LUIS", 150);

	std::cout << two;

	try {
		two.decrement();
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}

	Bureaucrat three("ANTONIO", 1);
	std::cout << three;

	try {
		three.increment();
		}
	catch(std::exception &exc)
	{
		std::cout << three;
		std::cout << exc.what();
	}
}