#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		virtual ~FragTrap();
		FragTrap(FragTrap const &copy);
	 	
		FragTrap	&operator=(FragTrap const &copy);
		void		highFivesGuys();
};

#endif