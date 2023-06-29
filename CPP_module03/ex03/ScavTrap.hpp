#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: virtual public ClapTrap
{
	protected:
		bool	_guard_gate;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		virtual ~ScavTrap();
		ScavTrap(ScavTrap const &copy);
	 	
		ScavTrap	&operator=(ScavTrap const &copy);
		void		guardGate();
};

#endif
