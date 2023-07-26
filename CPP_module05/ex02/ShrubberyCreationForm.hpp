#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>

class ShrubberyCreationForm: public Form
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string	target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &copy);
};

#endif
