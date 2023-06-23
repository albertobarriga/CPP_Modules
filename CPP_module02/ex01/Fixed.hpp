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
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif