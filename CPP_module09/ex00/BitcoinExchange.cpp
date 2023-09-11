#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy): _map(copy._map) {
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &copy) {
	if(this != &copy)
		_map = copy._map;
	return (*this);
}

bool	BitcoinExchange::check_line(std::string line) {
	if (line.find("|") == std::string::npos)
	{
		std::cout << "Error bad input"  << " => "<< line << std::endl;
		return 0;
	}
	else if (getValue(line, "|") < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	else if (getValue(line, "|") > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 0;
	}
	return(1);
}

float	BitcoinExchange::getValue(std::string line, std::string del)
{
	float		amount = 0.0;
	std::string number;

	number = line.substr(line.find(del) + 1, line.length());
	try {
		amount = std::atof(number.c_str());
	}
	catch(...) {
		std::cout << "ERROR: amount not valid" << std::endl;
	}
	return(amount);
}

std::time_t BitcoinExchange::getDate(std::string line, std::string del) {
	std::time_t date = 0;
	struct tm struct_temp;

	std::memset(&struct_temp, 0, sizeof(struct_temp));
	std::string date_string = line.substr(0, line.find(del));
	if (strptime(date_string.c_str(), "%Y-%m-%d", &struct_temp) != NULL)
	{
    	date = std::mktime(&struct_temp);
	}
	return date;
}

bool BitcoinExchange::GetDataBase(std::string file){
	std::string line;
	std::ifstream infile(file);
	if (!infile.is_open())
		return(1);
	while(std::getline(infile, line))
	{
		float amount = getValue(line, ",");
		time_t date = getDate(line, ",");
		this->_map[date] = amount;
	}

	return 0;
}

bool BitcoinExchange::GetFile(std::ifstream &infile){
	std::string line;
	float prize;
	time_t day = 86400;
	time_t date_temp;

	getline(infile, line);
	while(getline(infile, line))
	{
		if(check_line(line))
		{
			float amount = getValue(line, "|");
			time_t date = getDate(line, "|");
			std::map<std::time_t, float>::iterator iter = _map.find(date);
			if (iter != _map.end() && date != 0) {
				prize = iter->second;
				std::tm *tm_date;
					tm_date = std::localtime(&date);
					char buffer[80];
					strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_date);
					std::cout << buffer << " => " << amount << " = "<< prize * amount << std::endl;
			}
			else
			{
				int i = 0;
				date_temp = date;
				while (i < 3 && iter == _map.end())
				{
					date_temp -= day;
					iter = _map.find(date_temp);
					i++;
				}
				if (iter != _map.end() && date != 0) {
					prize = iter->second;

					std::tm *tm_date;
					tm_date = std::localtime(&date);
					char buffer[80];
					strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_date);
					std::cout << buffer << " => " << amount << " = "<< prize * amount << std::endl;
				}
				else
				{
					std::cout << "ERROR: Data is out of range"<< std::endl;
				}
			}
		}
	}
	return (0);
}

bool BitcoinExchange::CheckOpen(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string file_name = argv[1];
	std::ifstream infile(file_name);
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	if (this->GetDataBase("data.csv"))
		return(1);
	if (this->GetFile(infile))
		return(1);
	return (0);
}