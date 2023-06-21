#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
};

#endif
