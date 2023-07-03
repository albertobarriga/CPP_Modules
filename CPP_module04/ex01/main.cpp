#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main() {
    // const Animal* j = new Dog(); const Animal* i = new Cat();
    // delete j;//should not create a leak delete i;
    // return 0;
    
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
    
    }
    


