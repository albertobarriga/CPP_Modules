#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR: You can't have this grade, is too high.\n");
		}
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR: You can't have this grade, is too low.\n");
		}
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade){
	
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &copy) {
	_grade = copy._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::increment() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrement() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}


void	Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &excep)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << excep.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	(void) form;
}

std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &bure) {
	outstream << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".\n";
	return (outstream);
}