#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main()
{
	Zombie zombie("paco");
	zombie.announce();

	Zombie* muerto = newZombie("juan");
	muerto->announce();

	randomChump("PEDRO");

	delete muerto;
}