#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <Form.hpp>

class PresidentialPardonForm: public Form
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string	target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &copy);

		void execute(Bureaucrat const &executor) const;
};

#endif
