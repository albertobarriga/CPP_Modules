#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("default wrong_animal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal assigment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Default WrongAnimal doesn't make noise" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

