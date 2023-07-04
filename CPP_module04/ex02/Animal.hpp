#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
		Animal();

	public:
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &copy);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif
