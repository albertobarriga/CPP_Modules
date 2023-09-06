#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>

class BitcoinExchange
{
	private:
		std::map

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange	&operator=(BitcoinExchange const &copy);

		bool CheckOpen(int argc, char **argv);
		bool GetFile(std::ifstream &infile);
		bool GetDataBase(std::string &file);
};

#endif
