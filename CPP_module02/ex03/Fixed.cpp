#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fract_bits = 8;

Fixed::Fixed(): _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	_value = num << _fract_bits;
}

Fixed::Fixed(const float num) {
	_value = roundf(num * (1 << _fract_bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator>(Fixed const &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator<(Fixed const &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>=(Fixed const &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<=(Fixed const &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator==(Fixed const &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(Fixed const &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->_value--;
	return (tmp);
}

const Fixed	&Fixed::min(Fixed const &copy1, Fixed const &copy2)
{
	if (copy1 < copy2)
		return (copy1);
	return (copy2);
}

const Fixed &Fixed::max(Fixed const &copy1, Fixed const &copy2)
{
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
}


int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	float num;

	num = (float)_value / (1 << _fract_bits);
	return (num);
}

int		Fixed::toInt(void) const
{
	int num;

	num = _value >> _fract_bits;
	return (num);
}

std::ostream& operator<<(std::ostream& os, const Fixed& num)
{
	(void)num;
	os << num.toFloat();
	return os;
}