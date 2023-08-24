#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern first_intern;

	AForm *scf;
	// AForm *rrf;
	// AForm *ppf;

	scf = first_intern.makeForm("shrubbery creation", "one");
	// rrf = first_intern.makeForm("robotomy request", "two");
	// ppf = first_intern.makeForm("presidential pardon", "three");

}