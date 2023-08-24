#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;

	public:
		AForm();
		AForm(const std::string _name, const int grade_to_sign, const int grade_to_exec);
		virtual ~AForm();
		AForm(AForm const &copy);
		AForm	&operator=(AForm const &copy);

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

std::ostream	&operator<<(std::ostream &outstream, const AForm &frm);

#endif
