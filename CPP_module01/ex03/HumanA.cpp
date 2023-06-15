#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name) {}

HumanA::~HumanA() {
}

void HumanA::attack() {
	if (_weapon.getType() != "")
		std::cout << _weapon.getType() << std::endl;
}


