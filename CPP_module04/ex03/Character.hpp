#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "Materia.hpp"

class AMateria;

class ICharacter
{
	private:

	public:
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *inventory[4];
		AMateria *floor;

	public:
		Character();
		Character(std::string const &name);
		~Character();
		Character(Character const &copy);
		Character	&operator=(Character const &copy);

		std::string const & getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria * getInventory(int i) const;
};

#endif
