#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

class RobotomyRequestForm: public Form
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &copy);
};

#endif
