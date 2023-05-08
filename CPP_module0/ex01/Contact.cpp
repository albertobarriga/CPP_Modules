#include "Contact.hpp"


Contact::Contact(int index, std::string first_name, std::string last_name, std::string nickname) {
	_index = index;
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;

}
int	Contact::get_index() { return(_index); }
std::string	Contact::get_first_name(){ return(_first_name); }
std::string	Contact::get_last_name(){ return(_last_name); }
std::string	Contact::get_nickname(){ return(_nickname); }