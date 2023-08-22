#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string	target): Form("PresidentialPardon", 25, 5), target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): Form(copy), target(copy.target) {

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {
	(void)copy;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
}