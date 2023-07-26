#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string	target): Form("ShrubberyCreation", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): Form(copy), target(copy.target) {

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {
	(void)copy;
	return (*this);
}


