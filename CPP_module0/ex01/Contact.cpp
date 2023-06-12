#include "Contact.hpp"

Contact::Contact(): _first_name(""), _last_name(""), _nickname("") {}
Contact::Contact(std::string first_name, std::string last_name, std::string nickname) {
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;

}

std::string	Contact::get_first_name() { 
	if (_first_name.size() >= 10)
		return (_first_name.substr(0, 9) + ".");
	return(_first_name);
}

std::string	Contact::get_last_name() {
	if (_last_name.size() >= 10)
		return (_last_name.substr(0, 9) + ".");
	return(_last_name);
}

std::string	Contact::get_nickname() { 
	if (_nickname.size() >= 10)
		return (_nickname.substr(0, 9) + ".");
	return(_nickname); }

void Contact::print_info() {
	std::cout << "|" << "|" << _first_name << "|" << _last_name << "|" << _nickname << std::endl;
}
void Contact::add_contact() {
	std::cout << "Introduce nombre: ";
	std::cin >> _first_name;
	std::cout << "Introduce apellido: ";
	std::cin >> _last_name;
}
