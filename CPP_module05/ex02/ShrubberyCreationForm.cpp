#include "ShrubberyCreationForm.hpp"
#include <ios>
#include <fstream>

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

void ShrubberyCreationForm::personal_execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::string	tree_ascii;
	std::ofstream outfile;
	std::string filename;

	// Form::execute(executor);
	tree_ascii = 
	"                              # #### ####\n"
    "                            ### //#|### |/####\n"
    "                           ##//#/ /||/##/_/##/_#\n"
    "                         ###  //###|/ // # ###\n"
    "                       ##_/_#/_/## | #/###_/_####\n"
    "                      ## #### # / #| /  #### ##/##\n"
    "                       __#_--###`  |{,###---###-~\n"
    "                                 / }{\n"
    "                                  }}{\n"
    "                                  }}{\n"
    "                             ejm  {{}\n"
    "                            , -=-~{ .-^- _\n";

	filename = this->target + "_shrubbery";
	outfile.open(filename, std::ios::out);
	if (!outfile)
	{
		std::cout << "error opening the file" << std::endl;
		return;
	}
	for (int i = 0; i < 3; i++)
		outfile << tree_ascii << std::endl;
	outfile.close();
                                       
}