#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
	private:
		bool	_guard_gate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap const &copy);

		ScavTrap	&operator=(ScavTrap const &copy);

		void		guardGate();
};

#endif
