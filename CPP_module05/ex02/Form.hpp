#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;

	public:
		Form();
		Form(const std::string _name, const int grade_to_sign, const int grade_to_exec);
		virtual ~Form();
		Form(Form const &copy);
		Form	&operator=(Form const &copy);

		std::string	getName() const;
		bool	getIsSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;

		void	beSigned(Bureaucrat &bure);

		virtual void execute(Bureaucrat const &executor) const;
		virtual void personal_execute(Bureaucrat const &executor) const = 0;

		class	GradeTooHighException;
		class	GradeTooLowException;
		class	NotSignedExcep;
};

std::ostream	&operator<<(std::ostream &outstream, const Form &frm);

#endif
