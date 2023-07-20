#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <cstdlib>

void    ft_leaks()
{
    system("leaks -q AAnimal");
}
int main() {
    atexit(ft_leaks);
    int num = 10;
    const Animal* animals[num];

    std::cout << "creating animals" << std::endl;

    for (int i = 0; i < num; i++)
    {
        std::cout << "Creating animal " << i + 1 << std::endl;
        if (i < num / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "deleting animals" << std::endl;

    for (int i = 0; i < num; i++)
    {
        std::cout << "delete animal" << i + 1 << std::endl;
        delete animals[i];
    }
    
    std::cout  << std::endl << "creating copies" << std::endl << std::endl;

    const Cat* cats[2];

    // const Animal* animal;
    // animal = new Animal();
    // animal->makeSound();

    cats[0] = new Cat;
    cats[0]->makeSound();
    cats[1] = new Cat(*cats[0]);
    delete cats[0];
    cats[1]->makeSound();
    delete cats[1];
    return (0);
    }
    


