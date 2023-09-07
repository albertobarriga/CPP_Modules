#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	BitcoinExchange exchange;

	if (exchange.CheckOpen(argc, argv))
		return (1);
}