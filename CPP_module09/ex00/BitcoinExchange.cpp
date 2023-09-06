


bool BitcoinExchange::GetDataBase(std::string &file){

}

bool BitcoinExchange::GetFile(std::ifstream &infile){

}

bool BitcoinExchange::CheckOpen(int argc, char **argv) {
	if (argc != 2)
		return (1);
	std::string file_name = argv[1];
	std::ifstream infile(filename);
	if (!infile.is_open())
		return(1);
	if (this->GetFile(infile));
		return(1);
	if (this->GetDataBase("data.csv"))
}