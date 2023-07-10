#include "Character.hpp"

ICharacter::~ICharacter() {

}
Character::Character() {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->floor = NULL;
}

Character::~Character() {
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->inventory[i] != NULL)
	// 	{
	// 		delete this->inventory[i];
	// 		this->inventory[i] = NULL;
	// 	}
	// }
	// if (this->floor != NULL)
	// 	delete (this->floor);
}

Character::Character(Character const &copy) {
	// for (int i = 0, i < 4, i++)
	// 	this->inventory[i] = NULL;
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
	for (i = 0; i < 4; i++)
	{
		if (copy.getInventory(i))
			this->inventory[i] = copy.getInventory(i)->clone();
	}
	if (this->floor != NULL)
		delete (this->floor);
	this->floor = copy.floor;
	return (*this);
}

AMateria * Character::getInventory(int i) const {
	return (this->inventory[i]);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	int i = 0;

	while (this->inventory[i] && i < 4)
	{
		i++;
	}
	if (i < 4)
	{
		this->inventory[i] = m;
		// std::cout << "Equip index :" << i << std::endl;
	}
}

void Character::unequip(int idx) {
	if (this->inventory[idx] != NULL && idx < 4)
	{
		if (this->floor == NULL)
			this->floor = this->inventory[idx];
		else
		{
			std::cout << "Floor es full" << std::endl;
			return ;
		}
		this->inventory[idx] = NULL;
		std::cout << "Unequip index :" << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
		// std::cout << "Use index :" << idx << std::endl;
}
