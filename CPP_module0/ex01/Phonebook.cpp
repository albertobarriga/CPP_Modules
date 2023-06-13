#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): index(0) {}

void PhoneBook::add_contact() {
	if (index < 8)
	{
		contacts[index].add_contact();
		index++;
	}
	else if (index_aux < 8)
	{
		contacts[index_aux].add_contact();
		index_aux++;
	}
	else if (index_aux == 8)
	{
		index_aux = 0;
		contacts[index_aux].add_contact();
		index_aux++;
	}
}

void PhoneBook::print_info() {
		std::cout << "|" << std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << "|" << std::setw(10) << i
			<< "|" << std::setw(10) << contacts[i].get_first_name()
			<< "|" << std::setw(10) << contacts[i].get_last_name()
			<< "|" << std::setw(10) << contacts[i].get_nickname() << std::endl;
	}
}

void PhoneBook::print_contact(int ind) {
	contacts[ind].print_info(ind);
}