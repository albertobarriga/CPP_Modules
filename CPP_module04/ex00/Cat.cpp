#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "CAT";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat  &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat operator assigment called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << this->getType() << ": MEAOWWWWW" << std::endl;
}