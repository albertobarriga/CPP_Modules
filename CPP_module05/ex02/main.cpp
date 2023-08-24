#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat one("JOSE", 1);
	Bureaucrat two("LUIS", 150);
	ShrubberyCreationForm tree("arbusto");
	RobotomyRequestForm robot("bender");
	PresidentialPardonForm presi("pedro");
	// one.signForm(tree);
	try {
		one.signForm(tree);
		two.signForm(tree);
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}
	two.executeForm(tree);
	one.executeForm(tree);


	try {
		one.signForm(robot);
		// two.signForm(robot);
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}
	// two.executeForm(robot);
	one.executeForm(robot);


	try {
		one.signForm(presi);
		// two.signForm(presi);
		}
	catch(std::exception &exc)
	{
		std::cout << exc.what();
	}
	two.executeForm(presi);
	one.executeForm(presi);

	// Form mod1 = Form("mod1", 155, 6);

}