#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl project;

	std::cout << "CALL TO DEBUG" << std::endl;
	project.complain("DEBUG");

	std::cout << "CALL TO INFO" << std::endl;
	project.complain("INFO");

	std::cout << "CALL TO WARNING" << std::endl;
	project.complain("WARNING");

	std::cout << "CALL TO ERROR" << std::endl;
	project.complain("ERROR");
}