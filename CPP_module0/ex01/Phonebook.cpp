#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

void PhoneBook::add_contact() {
	contacts[index].add_contact();
	index++; // TODO que no pase de 8
}

void PhoneBook::print_info() {
	for (int i = 0; i < index; i++) {
		std::cout << "|" << std::setw(10) << i
			<< "|" << std::setw(10) << contacts[i].get_first_name()
			<< "|" << std::setw(10) << contacts[i].get_last_name()
			<< "|" << std::setw(10) << contacts[i].get_nickname() << std::endl;
	}
}

void PhoneBook::print_contact(int ind) {
	contacts[ind].print_info();
}