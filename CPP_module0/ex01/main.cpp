#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook book;
	std::string order;
	std::string input;

	while (true) {
		std::cout << "Phonebook is ready, you can do ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, order))
		{
			std::cout << std::endl << "PROGAM EXIT" << std::endl;
			break;
		}
		if (order == "ADD")
			book.add_contact();
		else if (order == "SEARCH") {
			book.print_info();
			std::cout << "What contact are you looking for? :";
			std::getline(std::cin, input);
			if (input == "0" || input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7")
				book.print_contact(atoi(input.c_str()));
			else 
				std::cout << "ERROR INPUT" << std::endl;
		}
		else if (order == "EXIT")
			return 0;
	}
}