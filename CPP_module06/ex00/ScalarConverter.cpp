#include "ScalarConverter.hpp"

char 			ScalarConverter::c = 0;
int				ScalarConverter::i = 0;
float			ScalarConverter::f = 0;
double			ScalarConverter::d = 0;
char 			ScalarConverter::type = 0;

int 			ScalarConverter::flag_c = 0;
int 			ScalarConverter::flag_i = 0;
int 			ScalarConverter::flag_f = 0;
int 			ScalarConverter::flag_d = 0;


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
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 1:
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 2:
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 3:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type = 'd';
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 4:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type = 'd';
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 5:
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type ='d';
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			break;
		case 6:
			break;
	};
}

void ScalarConverter::PrintInfo() {
	if (ScalarConverter::flag_c == 1)
		std::cout << "char: " << "impossible"<< std::endl;
	else if (ScalarConverter::i < 31 || ScalarConverter::i >= 127)
		std::cout << "char: " << "Non displayable"<< std::endl;
	else
		std::cout << "char: '" << ScalarConverter::c << "'"<< std::endl;
	if (ScalarConverter::flag_i == 1)
		std::cout << "int: " << "impossible"<< std::endl;
	else
		std::cout << "int: " << ScalarConverter::i << std::endl;


	if (ScalarConverter::flag_f == 1)
		std::cout << "float: " << "impossible"<< std::endl;
	else
	{
		if (static_cast<int>(ScalarConverter::f) - ScalarConverter::f == 0)
			std::cout << "float: " << ScalarConverter::f << ".0f"<< std::endl;
		else
			std::cout << "float: " << ScalarConverter::f << "f"<< std::endl;
	}

	if (ScalarConverter::flag_d == 1)
		std::cout << "double: " << "impossible"<< std::endl;
	else
	{
		if (static_cast<int>(ScalarConverter::d) - ScalarConverter::d == 0)
			std::cout << "double: " << ScalarConverter::d << ".0" << std::endl;
		else
			std::cout << "double: " << ScalarConverter::d << std::endl;
	}


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
			if (ScalarConverter::f <= INT_MIN || ScalarConverter::f >= INT_MAX)
				ScalarConverter::flag_i = 1;
			else
				ScalarConverter::i = static_cast<int>(ScalarConverter::f);
			ScalarConverter::d = static_cast<double>(ScalarConverter::f);
			break;
		case 'd':
			ScalarConverter::c = static_cast<char>(ScalarConverter::d);
			if (ScalarConverter::d <= INT_MIN || ScalarConverter::d >= INT_MAX)
				ScalarConverter::flag_i = 1;
			else
				ScalarConverter::i = static_cast<int>(ScalarConverter::d);
			ScalarConverter::f = static_cast<float>(ScalarConverter::d);
			break;
		default :
			ScalarConverter::flag_c = 1;
			ScalarConverter::flag_i = 1;
			ScalarConverter::flag_f = 1;
			ScalarConverter::flag_d = 1;
	};
}

void ScalarConverter::convert(std::string const &literal)
{
	ScalarConverter::SpecialOptions(literal);

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		ScalarConverter::c = literal[0];
		ScalarConverter::type = 'c';

		std::cout << ScalarConverter::c << std::endl;
	}
	int j = 0;
	int	f = 0;
	int p = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[0] == '-')
			break;
		if (!std::isdigit(literal[i]))
			j = 1;
		if ((i + 1) == literal.length() && literal[i] == 'f')
			f = 1;
		if (literal[i] == '.')
		{
			if (p == 1)
			{
				ScalarConverter::flag_c = 1;
				ScalarConverter::flag_i = 1;
				ScalarConverter::flag_f = 1;
				ScalarConverter::flag_d = 1;
			}
			p = 1;
		}
	}

	if (j == 1 && p == 1)
	{
		if (f == 1)
		{
			ScalarConverter::f = std::stof(literal);
			ScalarConverter::type = 'f';
		}
		else
		{
			ScalarConverter::d = std::stod(literal);
			ScalarConverter::type = 'd';
		}
	}
	else if (ScalarConverter::type == 0)
	{
		try {
			ScalarConverter::i = std::stol(literal);
			ScalarConverter::type = 'i';
			}
		catch (...) {
				ScalarConverter::flag_c = 1;
				ScalarConverter::flag_i = 1;
				ScalarConverter::flag_f = 1;
				ScalarConverter::flag_d = 1;
		}
	}

	ScalarConverter::Cast();
	ScalarConverter::PrintInfo();
}