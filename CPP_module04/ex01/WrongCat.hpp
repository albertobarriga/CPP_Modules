#include "WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include <iostream>

class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &copy);
		WrongCat	&operator=(WrongCat const &copy);

		void makeSound() const;
};

#endif
