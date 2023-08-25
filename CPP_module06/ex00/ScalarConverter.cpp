#include "ScalarConverter.hpp"

char 			ScalarConverter::c = 0;
int				ScalarConverter::i = 0;
float			ScalarConverter::f = 0;
double			ScalarConverter::d = 0;
char 			ScalarConverter::type = 0;



ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &copy) {
	(void)copy;
	return *this;
}

void ScalarConverter::SpecialOptions(std::string const &literal) {
	int pos = -1;
	int i;

	std::string special[6] = {
		"-inff",
		"+inff",
		"nanf" ,
		"-inf",
		"+inf",
		"nan" 
	};

	for (i = 0; i < 6; i++) {
		pos = literal.find(special[i]);
		if (pos == 0)
			break;
	}

	switch (i)
	{
		case 0:
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
			break;
		case 1:
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
			break;
		case 2:
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
			break;
		case 3:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type = 'd';
			break;
		case 4:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type = 'd';
			break;
		case 5:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type ='d';
			break;
		case 6:
			break;
	};
	return (0);
}

void ScalarConverter::PrintInfo() {
	std::cout << "char: '" << ScalarConverter::c << "'"<< std::endl;
	std::cout << "int: " << ScalarConverter::i << std::endl;
	if (static_cast<int>(ScalarConverter::f) - ScalarConverter::f == 0)
		std::cout << "float: " << ScalarConverter::f << ".0f"<< std::endl;
	else
		std::cout << "float: " << ScalarConverter::f << "f"<< std::endl;

	if (static_cast<int>(ScalarConverter::d) - ScalarConverter::d == 0)
		std::cout << "double: " << ScalarConverter::d << ".0" << std::endl;
	else
		std::cout << "double: " << ScalarConverter::d << std::endl;
}

void ScalarConverter::Cast() {
	switch (ScalarConverter::type)
	{
		case 'c':
			ScalarConverter::i = static_cast<int>(ScalarConverter::c);
			ScalarConverter::f = static_cast<float>(ScalarConverter::c);
			ScalarConverter::d = static_cast<double>(ScalarConverter::c);
			break;
		case 'i':
			ScalarConverter::c = static_cast<char>(ScalarConverter::i);
			ScalarConverter::f = static_cast<float>(ScalarConverter::i);
			ScalarConverter::d = static_cast<double>(ScalarConverter::i);
			break;
		case 'f':
			ScalarConverter::c = static_cast<char>(ScalarConverter::f);
			ScalarConverter::i = static_cast<int>(ScalarConverter::f);
			ScalarConverter::d = static_cast<double>(ScalarConverter::f);
			break;
		case 'd':
			ScalarConverter::c = static_cast<char>(ScalarConverter::d);
			ScalarConverter::i = static_cast<int>(ScalarConverter::d);
			ScalarConverter::f = static_cast<float>(ScalarConverter::d);
			break;
	};
}

void ScalarConverter::convert(std::string const &literal)
{
	if(ScalarConverter::SpecialOptions(literal))
	{

	}
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		ScalarConverter::c = literal[0];
		ScalarConverter::type = 'c';
		ScalarConverter::i = static_cast<int>(ScalarConverter::c);
		ScalarConverter::f = static_cast<float>(ScalarConverter::c);
		ScalarConverter::d = static_cast<double>(ScalarConverter::c);

		std::cout << ScalarConverter::c << std::endl;
	}
	// std::cout << literal << std::endl;


	ScalarConverter::Cast();
	ScalarConverter::PrintInfo();
	// std::cout << "char: '" << ScalarConverter::c << "'"<< std::endl;
	// std::cout << "int: " << ScalarConverter::i << std::endl;
	// std::cout << "float: " << ScalarConverter::f << std::endl;
	// std::cout << "double: " << ScalarConverter::d << std::endl;
}