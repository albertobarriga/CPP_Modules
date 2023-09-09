#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// int main ()
// {
// 	std::cout << "creating a empty array: "<< std::endl;
// 	Array<int> empty;
// 	std::cout << "size of a empty array: " << empty.size() << std::endl;
// 	std::cout << "creating a array of 10 "<< std::endl;
// 	Array<int> numbers(10);
// 	std::cout << "size of a empty array: " << numbers.size() << std::endl;
	
// 	try {
// 		numbers[1] = 0;
// 	}
// 	catch (const char* e) {
// 		std::cout << e << std::endl;
// 	}
	
// 	try {
// 		numbers[11] = 0;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }