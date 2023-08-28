#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>


class Base
{
	private:

	public:
		Base();
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base	*p);
void	identify(Base	&p);
#endif
