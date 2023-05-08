#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
			Contact(int index, std::string first_name, std::string last_name, std::string nickname);
			inline int	get_index(){return _index;};
			inline std::string	get_first_name(){return _first_name;};
			inline std::string	get_last_name(){return _last_name;};
			inline std::string	get_nickname(){return _nickname;};
	private:
			int	_index;
			std::string _first_name;
			std::string _last_name;
			std::string _nickname;
};

#endif