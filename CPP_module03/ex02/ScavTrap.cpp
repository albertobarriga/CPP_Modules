#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_points = 20;
	this->_guard_gate = false;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	this->_guard_gate = copy._guard_gate;
	std::cout << "ScavTrap call copy constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_points = 20;
	this->_guard_gate = false;
	std::cout << "ScavTrap Constructor for the name " << this->_name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "ScavTrap operator called" << std::endl;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_points = copy._attack_points;
	this->_guard_gate = copy._guard_gate;
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (this->_guard_gate == false)
	{
		this->_guard_gate = true;
		std::cout << "ScavTrap" << this->_name << " is starting guarding the gate" << std::endl;
	}
	else
		std::cout << "ScavTrap" << this->_name << " it was already guarding the gate" << std::endl;

}


