#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog  &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog operator assigment called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->getType() << ": GUAUU" << std::endl;
}