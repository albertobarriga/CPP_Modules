#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();

		void add_contact();
		void print_info();
		void print_contact(int ind);
		// void set_information();
		// void get_information();
		// void show_instruction();
		int	index_aux;
	private:
		Contact	contacts[8];
		int index;
		// bool full;
};
#endif