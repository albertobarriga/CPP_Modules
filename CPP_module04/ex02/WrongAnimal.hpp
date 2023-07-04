#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal	&operator=(WrongAnimal const &copy);

		void makeSound()const;
		std::string getType() const;
};

#endif
