#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>


class Contact
{
	public:
		Contact();
		~Contact();

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		void print_info(int ind);
		void add_contact();

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkest_secret;
};

#endif