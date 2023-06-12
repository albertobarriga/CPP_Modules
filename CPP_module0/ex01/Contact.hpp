#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>


class Contact
{
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname);

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		void print_info();
		void add_contact();

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
};

#endif