#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook book;
	std::string order;
	int index;

	while (true) {
		std::cout << "agenda lista: haz addd, search o exit";
		std::cin >> order;
		if (order == "ADD")
			book.add_contact();
		// if (order == ADD)
		// book.add_contact();
		if (order == "SEARCH") {
			book.print_info();
			std::cout << "¿Que contacto buscas?";
			std::cin >> index;
			book.print_contact(index);
		}
		if (order == "EXIT")
			return 0;
	}
}