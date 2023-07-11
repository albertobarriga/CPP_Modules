#include "Materia.hpp"
#include "Character.hpp"
#include "IMateria.hpp"

void    ft_leaks()
{
    system("leaks -q Interface");
}
int main()
{
	atexit(ft_leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* ice;
	AMateria* cure;
	AMateria* ice1;
	AMateria* cure1;
	AMateria* cure2;
	AMateria* ice2;

	ice = src->createMateria("ice");
	me->equip(ice);
	cure = src->createMateria("cure");
	me->equip(cure);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->use(2, *bob);               //empty materia
	me->unequip(3);                 //unequip a empty
	ice1 = src->createMateria("ice");
	me->equip(ice1);                 //equip the 3rd materia
	me->equip(ice1);                 //equip the 4rd materia and full
	cure1 = src->createMateria("cure");
	me->equip(cure1);                 //full equip
	me->unequip(3);                 //floor one thing
	cure2 = src->createMateria("cure");
	me->equip(cure2);                 //equip slot 3
	me->unequip(3);                 //floor is full, problem
	ice2 = src->createMateria("ice");
	me->equip(ice2);                 //equip

	delete ice;
	delete ice1;
	delete ice2;
	delete cure;
	delete cure1;
	delete cure2;
	delete bob;
	delete me;
	delete src;
	return 0;
}
