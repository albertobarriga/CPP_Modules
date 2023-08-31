#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class DoesntExist: public std::exception
{
	public:
		virtual const char* what() const throw() {
			return("ERROR: No match found\n");
		}
};

template<typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator pos;

	pos = std::find(container.begin(), container.end(), n);
	if (pos == container.end())
		throw (DoesntExist());
	else
	{
		return(pos);
	}
}

#endif