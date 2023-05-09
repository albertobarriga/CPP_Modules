#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();

		// void set_information();
		// void get_information();
		// void show_instruction();
	private:
		Contact	contacts[8];
		// int index;
		// bool full;
};
#endif