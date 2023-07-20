#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("JULIO");

	a.attack("robot");
	a.takeDamage(1);
	a.takeDamage(1);
	a.beRepaired(5);
	a.takeDamage(10);
	a.takeDamage(15);
	a.beRepaired(5);
}