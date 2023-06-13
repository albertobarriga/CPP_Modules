#include "Contact.hpp"

Contact::Contact() {
}
Contact::~Contact() {
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

void Contact::print_info(int ind) {
	std::cout << "| " << ind << "| " << _first_name << "| " << _last_name << "| " << _nickname << "| " << _phonenumber << "| " << _darkest_secret << std::endl;
}
void Contact::add_contact() {
	std::cout << "Enter first_name: ";
	std::cin >> _first_name;
	std::cout << "Enter last_name: ";
	std::cin >> _last_name;
	std::cout << "Enter nickname: ";
	std::cin >> _nickname;
	std::cout << "Enter number: ";
	std::cin >> _phonenumber;
	std::cout << "Enter secret: ";
	std::cin >> _darkest_secret;
}
