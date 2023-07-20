#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain assigment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
    {
        if(copy._ideas[i].length() > 0)
            this->_ideas[i].assign(copy._ideas[i]);
    }
	return (*this);
}
