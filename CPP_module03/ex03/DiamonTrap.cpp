#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("defaultClassTrap")
{
	this->_name = "defaultClassTrap";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_points = FragTrap::_attack_points;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap call copy constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_points = FragTrap::_attack_points;
	std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << "DiamondTrap operator called" << std::endl;
	this->_name = copy.name  + "_clap_name";
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_points = copy._attack_points;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Hello name" << std::endl;
}
