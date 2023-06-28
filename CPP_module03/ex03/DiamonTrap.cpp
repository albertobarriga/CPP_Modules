#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_points = 30;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "FragTrap call copy constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_points = 20;
	std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "FragTrap operator called" << std::endl;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_points = copy._attack_points;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "High Fives Guys" << std::endl;
}
