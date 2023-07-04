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

// const std::string Brain::getIdea(size_t i)const
// {
//     if (i < 100)
//         return (this->_ideas[i]);
//     else
//         return ("There is only 100 ideas");
// }

// const std::string *Brain::getAddressIdea(size_t i) const
// {
//     if (i < 100)
//     {
//         const std::string &stringREF = this->_ideas[i];
//         return (&stringREF);
//     }
//     else
//         return (NULL);
// }

// void Brain::setIdea(size_t i, std::string idea)
// {
//     if (i < 100)
//         this->_ideas[i] = idea;
//     else
//         std::cout << "There is only 100 ideas" << std::endl;
// }
