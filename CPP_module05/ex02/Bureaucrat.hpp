#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat	&operator=(Bureaucrat const &copy);

		std::string	getName() const;
		int		getGrade() const;

		void	increment();
		void	decrement();

		void	signForm(Form &form);

		void	executeForm(Form const &form);

		class	GradeTooHighException;
		class	GradeTooLowException;

};

std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &bure);
#endif
