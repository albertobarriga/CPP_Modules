#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern	&operator=(Intern const &copy);

		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
