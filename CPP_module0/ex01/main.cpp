#include "Contact.cpp"
#include <iostream>

int main()
{
	Contact miContacto(1, "alberto", "barriga", "barrigadam");

	std::cout << miContacto.get_index();
	return 0;
}