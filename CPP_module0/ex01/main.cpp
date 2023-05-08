#include "Contact.hpp"
#include <iostream>

int main()
{
	Contact myContact(1, "alberto", "barriga", "barrigadam");

	std::cout << myContact.get_index() << std::endl;
	return 0;
}