#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}
void	Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-"
	"special-ketchup burger. I really do!\n";

}

void	Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming"
"for years whereas you started working here since last month.\n";
}

void	Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

int	Harl::get_level(std::string level) {
	std::string levels[5];
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2]= "WARNING";
	levels[3] = "ERROR";

	int arg;
	for (arg = 0; levels[arg] != level && arg < 4; arg++) {
	}
	return (arg);
}

// In this function we declarate a string on a sequence.

void	Harl::filter(std::string level) {

	void (Harl::*ptrs[])(void) = {
		ptrs[0] = &Harl::debug,
		ptrs[1] = &Harl::info,
		ptrs[2] = &Harl::warning,
		ptrs[3] = &Harl::error,
	};

	int lvl = get_level(level);

	switch (lvl)
	{
		case 0:
				std::cout << "[ DEBUG ]\n";
				while (lvl < 4) {
					(this->*ptrs[lvl])();
					lvl++;
				};
				break;
		case 1:
				std::cout << "[ INFO ]\n";
				while (lvl < 4) {
					(this->*ptrs[lvl])();
					lvl++;
				};
				break;
		case 2:
				std::cout << "[ WARNING ]\n";
				while (lvl < 4) {
					(this->*ptrs[lvl])();
					lvl++;
				};
				break;
		case 3:
				std::cout << "[ ERROR ]\n";
				while (lvl < 4) {
					(this->*ptrs[lvl])();
					lvl++;
				};
				break;
		default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
