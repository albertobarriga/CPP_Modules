#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{

}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hits_points(10), _energy_points(10), _attack_points() {

}

ClapTrap::~ClapTrap() {

}

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy)
{
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_points = copy._attack_points;
	return (*this);
}

	void attack(const std::string &target) 
	{

		if (this->_energy_points > 0 && this->_hit_points > 0)
		{
			this->_energy_points--;
		}
		else if (this->_energy_points == 0)
			std::cout << this->_name << "it can't to attack" << target << "because it not has not enought energy" << std::endl;
		else
			std::cout << this->_name << "it can't to attack" << target << "because it not has not enought hit points" << std::endl;

	}