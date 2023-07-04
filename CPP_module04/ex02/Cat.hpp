#ifndef CAT_HPP
#define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal 
{
	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &copy);

		void makeSound() const;
};

#endif
