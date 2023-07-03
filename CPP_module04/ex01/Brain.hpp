#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		~Brain();
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &copy);

		// const std::string getIdea(size_t i) const;
		// const std::string *getAddressIdea(size_t i) const;

		// void setIdea(size_t i, std::string idea);
};

#endif