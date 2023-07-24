#include "Bureaucrat.hpp"
#include "Form.hpp"

class Form::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR exception grade is too high.\n");
		}
};

class Form::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR exception grade is too low.\n");
		}
};

Form::Form() : is_signed(false), grade_to_sign(0), grade_to_exec(0) {
	std::cout << "ha entrado en el constructor simple" << std::endl;
}

Form::Form(const std::string _name, const int grade_sign, const int grade_exec): _name(_name), is_signed(false), grade_to_sign(grade_sign), grade_to_exec(grade_exec) {
    std::cout << "ha entrado en el constructor complejo" << std::endl;
	if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooLowException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooHighException();
}

Form::Form(Form const &copy): _name(copy._name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec){
}

Form::~Form() {

}

Form	&Form::operator=(Form const &copy) {
    is_signed = copy.is_signed;
    // _name = copy.getName();
    // _name = copy._name;
	// grade_to_sign = copy.grade_to_sign;
	// grade_to_exec = copy.grade_to_exec;
	(void)copy;
    return *this;
}

std::string	Form::getName() const {
	return(this->_name);
}

bool	Form::getIsSigned() const {
	return(this->is_signed);
}

int		Form::getGradeSign() const {
	return(this->grade_to_sign);
}

int		Form::getGradeExec() const {
	return(this->grade_to_exec);
}

void	Form::beSigned(Bureaucrat &bure) {
	std::cout << "ha entrad en signed con un burocrata de grado " << bure.getGrade() << " va a firmar un form " << this->getGradeSign() << std::endl;
	if (bure.getGrade() <= this->getGradeSign())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &outstream, const Form &frm)
{
	outstream << "The form " << frm.getName() << " has this grade to sign " << frm.getGradeSign() << ", has this grade to be executed " << frm.getGradeExec() << " and is it signed ->" << frm.getIsSigned() << std::endl;
	return(outstream);
}