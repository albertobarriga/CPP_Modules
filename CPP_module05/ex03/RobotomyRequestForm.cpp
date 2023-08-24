#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string	target): AForm("RobotomyRequest", 72, 45), target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy), target(copy.target)
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	(void)copy;
	return (*this);
}

void RobotomyRequestForm::personal_execute(Bureaucrat const &executor) const
{
	(void) executor;
	std::cout << this->target << " says **Bipp bipp bopp**" << std::endl;
	std::srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized succesfully" << std::endl;
	else
		std::cout <<"robotomized fail" << std::endl;
}

