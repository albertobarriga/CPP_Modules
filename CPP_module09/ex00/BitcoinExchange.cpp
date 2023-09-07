#include "BitcoinExchange.hpp"

bool	BitcoinExchange::check_line(std::string line) {
	if (line.find("|") == std::string::npos)
	{
		std::cout << "Error bad input" << std::endl;
		return 0;
	}
	else if (line.find("date") != std::string::npos)
	{
		std::cout << "Error bad input" << std::endl;
		return 0;
	}
	else if (getValue(line) < 0 || getValue(line) > 1000)
	{
		std::cout << "ERROR: bad amount input" << std::endl;
		return 0;
	}
	// else if (getDate(line))
	return(1);
}

float	BitcoinExchange::getValue(std::string line)
{
	float		amount = 0.0;
	std::string number;

	number = line.substr(line.find("|") + 1, line.length());
	try {
		amount = std::atof(number.c_str());
	}
	catch(...) {
		std::cout << "ERROR: amount not valid" << std::endl;
	}
	// std::cout << amount << std::endl;
	
	return(amount);
}

std::time_t BitcoinExchange::getDate(std::string line) {
	std::time_t date;

	std::string date_string = line.substr(0, line.find("|"));
	return date;
}

bool BitcoinExchange::GetDataBase(std::string &file){
	(void)file;
	return 0;
}

bool BitcoinExchange::GetFile(std::ifstream &infile){
	std::string line;
	while(getline(infile, line))
	{
		if(check_line(line))
		{
			float amount = getValue(line);
			time_t date = getDate(line);
		}
	}
	return (0);
}

bool BitcoinExchange::CheckOpen(int argc, char **argv) {
	if (argc != 2)
		return (1);
	std::string file_name = argv[1];
	std::ifstream infile(file_name);
	if (!infile.is_open())
		return(1);
	if (this->GetFile(infile))
		return(1);
	// if (this->GetDataBase("data.csv"))
		return(1);
}