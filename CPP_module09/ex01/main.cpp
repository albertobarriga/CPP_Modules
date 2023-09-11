#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN calculator;
	if (argc != 2)
	{
		std::cout << "ERROR: BAD ARGUMENTS" << std::endl;
		return (1);
	}
	if (calculator.calculate(std::string(argv[1])))
		return (1);
	calculator.result();

}