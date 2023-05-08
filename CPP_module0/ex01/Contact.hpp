#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact(int index, std::string first_name, std::string last_name, std::string nickname);
		int	get_index();
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
	private:
		int	_index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
};

#endif