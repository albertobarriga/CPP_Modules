#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCAT";
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	*this = copy;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat  &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat operator assigment called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->getType() << ": mahouuuuu" << std::endl;
}