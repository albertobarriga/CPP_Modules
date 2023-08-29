#include "Array.hpp"

int main ()
{
	std::cout << "creating a empty array: "<< std::endl;
	Array<int> empty;
	std::cout << "size of a empty array: " << empty.size() << std::endl;
	std::cout << "creating a array of 10 "<< std::endl;
	Array<int> numbers(10);
	std::cout << "size of a empty array: " << numbers.size() << std::endl;
	
	try {
		numbers[1] = 0;
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
	
	try {
		numbers[11] = 0;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}