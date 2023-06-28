#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hit_points(10), _energy_points(10), _attack_points(0)
{
	std::cout << "call to the constructor ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "call to the copy constructor" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_points(0) {
	std::cout << "call to the constructor" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "call to the destructor" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << "call to the operator constructor" << std::endl;
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_points = copy._attack_points;
	return (*this);
}

void ClapTrap::attack(const std::string &target) 
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_points << " points of damage!" << std::endl; 
	}
	else if (this->_energy_points == 0)
		std::cout << this->_name << "it can't to attack" << target << "because it has not enought energy" << std::endl;
	else
		std::cout << this->_name << "it can't to attack" << target << "because it has not enought hit points" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points >= amount)
	{
		this->_hit_points = this->_hit_points - amount;
		std::cout << "ClapTrap " << this->_name << " take damage and has " << this->_hit_points << " points of health" << std::endl; 
	}
	else if (this->_hit_points > 0)
	{
		this->_hit_points = 0;
		std::cout << "ClapTrap " << this->_name << " take damage and has " << this->_hit_points << " points of health" << std::endl; 

	}
	else
		std::cout << "it cant attack " << this->_name << "is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repaired and has " << this->_hit_points << " points of health" << std::endl; 
	}
	else if (this->_energy_points > 0)
		std::cout << this->_name << " cant repaired because not have health points" << std::endl;
	else
		std::cout << this->_name << " cant repaired because not have energy points" << std::endl;
}