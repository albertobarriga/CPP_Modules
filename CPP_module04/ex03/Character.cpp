#include "Character.hpp"

Character::Character() {
	for (int i = 0, i < 4, i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) _name(name) {
	for (int i = 0, i < 4, i++)
		this->inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0, i < 4, i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

Character::Character(Character const &copy) {
	for (int i = 0, i < 4, i++)
		this->inventory[i] = NULL;
	*this = copy;
}

Character	&Character::operator=(Character const &copy)
{
	int i = 0;	
	this->_name = copy._name;
	while (this->inventory[i])
	{
		delete this->inventory[i];
		this->inventory[i] = NULL;
	}
	for (i = 0, i < 4, i++)
	{
		if (copy.getInventory(i))
			this->inventory[i] = copy.getInventory()->clone();
	}
	return (*this);
}

AMateria * Character::getInventory(int i) const {
	return (this->inventory[i]);
}

std::string const & getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	int i = 0;

	while (this->inventory[i] && i < 4)
		i++;
	if (i != 4)
		this->inventory[i] = m;
}

void Character::unequip(int idx) {
	if (this->inventory[i] != NULL)
		this->inventory[i] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
