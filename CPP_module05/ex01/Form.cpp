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
			return("ERROR exception grade is low high.\n");
		}
};

Form::Form() : is_signed(false), grade_to_sign(0), grade_to_exec(0) {

}

Form::Form(const std::string _name, const int grade_to_sign, const int grade_to_exec): _name(_name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec) {
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw GradeTooLowException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw GradeTooHighException();
}

Form::Form(Form const &copy): _name(copy._name), is_signed(copy.is_signed), grade_to_sign(copy.grade_to_sign), grade_to_exec(copy.grade_to_exec){
    return *this;
}

Form::~Form() {

}

Form	&Form::operator=(Form const &copy) {
    this->is_signed = copy.getIsSigned();
    this->_name = copy.getName();
    return *this;

}