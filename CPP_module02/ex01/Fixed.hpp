#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _fract_bits;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif

