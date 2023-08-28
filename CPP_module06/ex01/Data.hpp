#ifndef DATA_HPP
#define DATA_HPP

# include <iostream>

class Data
{
	private:
		std::string	_name;
	public:
		Data();
		~Data();
		Data(Data const &copy);
		Data	&operator=(Data const &copy);

		std::string getName() const;
};

#endif
