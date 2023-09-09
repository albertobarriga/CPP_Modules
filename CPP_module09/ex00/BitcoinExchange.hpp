#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <ctime>

class BitcoinExchange
{
	private:
		std::map<std::time_t, float>	_map;

	public:
		// BitcoinExchange();
		// ~BitcoinExchange();
		// BitcoinExchange(BitcoinExchange const &copy);
		// BitcoinExchange	&operator=(BitcoinExchange const &copy);

		bool CheckOpen(int argc, char **argv);
		bool GetFile(std::ifstream &infile);
		bool GetDataBase(std::string file);
		float	getValue(std::string line, std::string del);
		std::time_t getDate(std::string line, std::string del);
		bool	check_line(std::string line);
};

#endif
