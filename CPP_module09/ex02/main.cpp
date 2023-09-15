#include "PmergeMe.hpp"

bool only_digits(const std::string &str) {
	if (str.find_first_of("0123456789") != std::string::npos)
		return 0;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "ERROR: NO NUMBERS IN ARGUMENTS" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		if (only_digits(argv[i]))
		{
			std::cerr << "ERROR: Input not numeric" << std::endl;
		}
	}

	PmergeMe	algorithm;

	if (!algorithm.fill(&argv[1]))
	{
		algorithm.mergesort();
	}
	return (1);
}