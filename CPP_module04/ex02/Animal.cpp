#include "Animal.hpp"

Animal::Animal():_type("default")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << "Animal assigment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Default Animal doesn't make noise" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

