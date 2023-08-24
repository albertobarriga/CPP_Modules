#include "Intern.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(Intern const &copy) {
	*this = copy;
}

Intern	&Intern::operator=(Intern const &copy) {
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	(void) target;
	AForm *form = NULL;
	int number_form = -1;
	int i;

	std::string name_forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (i = 0; i < 3; i++) {
		number_form = name.find(name_forms[i]);
		// std::cout << number_form << std::endl;
		if (number_form == 0)
			break;
	}
	// std::cout << number_form << std::endl;

	std::cout << i << " en esta pos" << std::endl;

	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break;

		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			break;
		case 3:
			std::cout << "This form doesn't exist" << std::endl;
			break;
	};

	return (form);
}