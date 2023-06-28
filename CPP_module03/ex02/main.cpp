#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
	std::cout << "empieza el claptrap" << std::endl;
	ClapTrap a("JULIO");

	a.attack("robot");
	a.takeDamage(1);
	a.takeDamage(1);
	a.beRepaired(5);
	a.takeDamage(10);
	a.takeDamage(15);
	a.beRepaired(5);

	std::cout <<std::endl << "empieza el scavtrap" << std::endl << std::endl;

	ScavTrap c("Maria");

	c.attack("robot");
	c.takeDamage(1);
	c.takeDamage(1);
	c.beRepaired(5);
	c.guardGate();
	c.takeDamage(10);
	c.guardGate();
	c.takeDamage(15);
	c.beRepaired(5);

	std::cout <<std::endl << "empieza el flagtrap" << std::endl << std::endl;

	FragTrap d("JUANILLO");

	d.attack("hacha");
	d.takeDamage(1);
	d.takeDamage(1);
	d.beRepaired(5);
	d.highFivesGuys();
	d.takeDamage(10);
	d.highFivesGuys();
	d.takeDamage(15);
	d.beRepaired(5);

}
