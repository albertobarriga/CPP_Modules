#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat one("PACO", 155);
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}

	Bureaucrat two("LUIS", 150);

	try {
		two.decrement();
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}

	Bureaucrat three("ANTONIO", 1);

	try {
		three.increment();
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}
}