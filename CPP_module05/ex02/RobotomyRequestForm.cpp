#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string	target): Form("RobotomyRequest", 72, 45), target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): Form(copy), target(copy.target) {

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {
	(void)copy;
	return (*this);
}


