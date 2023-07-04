#include "Dog.hpp"
# include "Brain.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog  &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog operator assigment called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_type = copy._type;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->getType() << ": GUAUU" << std::endl;
}