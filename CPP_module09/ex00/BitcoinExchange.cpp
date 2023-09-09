#include "BitcoinExchange.hpp"

bool	BitcoinExchange::check_line(std::string line) {
	if (line.find("|") == std::string::npos)
	{
		std::cout << "Error bad input" << std::endl;
		return 0;
	}
	// else if (line.find("date") != std::string::npos)
	// {
	// 	std::cout << "Error bad input" << std::endl;
	// 	return 0;
	// }
	else if (getValue(line, "|") < 0 || getValue(line, "|") > 1000)
	{
		std::cout << "ERROR: bad amount input" << std::endl;
		return 0;
	}
	// else if (getDate(line))
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
	// std::cout << amount << std::endl;
	
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

	getline(infile, line);
	while(getline(infile, line))
	{
		if(check_line(line))
		{
			// int i = 0;
			float amount = getValue(line, "|");
			time_t date = getDate(line, "|");
			std::cout << "tiempo_input : " << date << std::endl;
			std::cout << "cantidad : " << amount << std::endl;
			// this->_map[date] = amount;
			std::map<std::time_t, float>::iterator iter = _map.find(date);
			if (iter != _map.end()) {
				prize = iter->second;
				std::cout << "precio : " << prize << std::endl;
			}
			else
			{
				int i = 0;
				while (i < 3 && iter == _map.end())
				{
					date -= day;
					// std::cout << "tiempo_input modificado : " << date << std::endl;
					iter = _map.find(date);
					i++;
				}
				if (iter != _map.end()) {
					prize = iter->second;
					std::cout << "precio : " << prize << std::endl;
				}
				else
				{
					std::cout << "ERROR: Data not exist"<< std::endl;
					return 1;
				}
			}
				std::cout << "tiempo_data : " << iter->first << std::endl;
		}
		std::cout << std::endl;
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
	if (this->GetDataBase("data.csv"))
		return(1);
	if (this->GetFile(infile))
		return(1);
	return (0);
}