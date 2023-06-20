#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon->getType() != "")
		std::cout << _weapon->getType() << std::endl;
	else
		std::cout << "cant attack because he has not weapon" << std::endl;

}


