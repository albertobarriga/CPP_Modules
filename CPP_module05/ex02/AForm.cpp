#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR exception grade is too high.\n");
		}
};

class AForm::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR exception grade is too low.\n");
		}
};

class AForm::NotSignedExcep: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("It can't be execute because is not signed\n");
		}
};

AForm::AForm() : is_signed(false), grade_to_sign(0), grade_to_exec(0) {
}

AForm::AForm(const std::string _name, const int grade_sign, const int grade_exec): _name(_name), is_signed(false), grade_to_sign(grade_sign), grade_to_exec(grade_exec) {
	if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooLowException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooHighException();
}

AForm::AForm(AForm const &copy): _name(copy._name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec){
}

AForm::~AForm() {

}

AForm	&AForm::operator=(AForm const &copy) {
    is_signed = copy.is_signed;
    return *this;
}

std::string	AForm::getName() const {
	return(this->_name);
}

bool	AForm::getIsSigned() const {
	return(this->is_signed);
}

int		AForm::getGradeSign() const {
	return(this->grade_to_sign);
}

int		AForm::getGradeExec() const {
	return(this->grade_to_exec);
}

void	AForm::beSigned(Bureaucrat &bure) {
	if (bure.getGrade() <= this->getGradeSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(!this->is_signed)
		throw AForm::NotSignedExcep();
	else if (executor.getGrade() > this->grade_to_exec)
		throw AForm::GradeTooLowException();
	personal_execute(executor);
}


std::ostream	&operator<<(std::ostream &outstream, const AForm &frm)
{
	outstream << "The form " << frm.getName() << " has this grade to sign " << frm.getGradeSign() << ", has this grade to be executed " << frm.getGradeExec() << " and is it signed ->" << frm.getIsSigned() << std::endl;
	return(outstream);
}
