#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat two("LUIS", 1);

	std::cout << two;

	try {
		two.decrement();
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}

	// try {
	// 	Form mod1 = Form("mod1", 155, 6);
	// 	std::cout << mod1;
	// 	}
	// catch(std::exception &exc)
	// {
	// 	std::cout << exc.what();
	// }

	Form mod2;
	// try {
	// 	mod2 = Form("mod2", 105, 6);
	// 	std::cout << mod2;
	// 	}
	// catch(std::exception &exc)
	// {
	// 	std::cout << exc.what();
	// }

	mod2 = Form("mod2", 105, 6);

	std::cout << mod2;

	two.signForm(mod2);
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