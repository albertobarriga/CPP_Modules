#include <string>
#include <iostream>

int main () {
	std::string variable = "HI THIS IS BRAIN";
	std::string *variablePtr = &variable;
	std::string &variableRef = variable;

	std::cout << "Address print: " << &variable << std::endl;
	std::cout << "Address print: " << &(*variablePtr) << std::endl;
	std::cout << "Address print: " << &variableRef << std::endl;

	std::cout << "Message print: " << variable << std::endl;
	std::cout << "Message print: " << *variablePtr << std::endl;
	std::cout << "Message print: " << variableRef << std::endl;
}