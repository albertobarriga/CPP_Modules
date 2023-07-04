#ifndef DOG_HPP
#define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &copy);

		void makeSound() const;
};

#endif
