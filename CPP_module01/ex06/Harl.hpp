#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {
	public:
		Harl();
		~Harl();
		int get_level(std::string level);
		void filter(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();
};
#endif