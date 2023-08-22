#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <Form.hpp>

class RobotomyRequestForm: public Form
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &copy);

		void execute(Bureaucrat const &executor) const;
};

#endif
