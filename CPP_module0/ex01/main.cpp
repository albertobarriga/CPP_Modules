#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook book;
	std::string order;
	int index;

	while (true) {
		std::cout << "Phonebook is ready, you can do ADD, SEARCH or EXIT: ";
		std::cin >> order;
		if (order == "ADD")
			book.add_contact();
		else if (order == "SEARCH") {
			book.print_info();
			std::cout << "What contact are you looking for? :";
			std::cin >> index;
			book.print_contact(index);
		}
		else if (order == "EXIT")
			return 0;
	}
}