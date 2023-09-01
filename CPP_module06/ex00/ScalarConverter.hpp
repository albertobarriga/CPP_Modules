#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits.h>


class ScalarConverter
{
	private:
		static char		c;
		static int		i;
		static float	f;
		static double	d;

		static char		type;

		static int 			flag_c;
		static int 			flag_i;
		static int 			flag_f;
		static int 			flag_d;
		
		ScalarConverter();
		
	public:

		~ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter	&operator=(ScalarConverter const &copy);
		static void	convert(std::string const &literal);
		static void	SpecialOptions(std::string const &literal);
		static void Cast();
		static void PrintInfo();
};

#endif
