#include <string>
#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Invalid number of arguments" << std::endl;
		return 0;
	}
	Harl project;

	project.filter(argv[1]);
}