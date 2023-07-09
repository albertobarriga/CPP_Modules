#include "Materia.hpp"
#include "Character.hpp"
#include "IMateria.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->use(2, *bob);               //empty materia
	me->unequip(3);                 //unequip a empty
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);                 //full equip
	// tmp = src->createMateria("cure");
	// me->equip(tmp);                 //throw to the floor inv. full
	// tmp = src->createMateria("ice");
	// me->equip(tmp);                 //floor is full

	delete bob;
	delete me;
	delete src;
	return 0;
}