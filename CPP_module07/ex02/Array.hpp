#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array {
	private:
		T			*_array;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(Array const &copy);
		Array	&operator=(Array const &copy);

		class OutRange: public std::exception {
			virtual const char *what() const throw();
		};
	unsigned int size() const;
	T &operator[](unsigned int index);

};

#include "Array.tpp"

#endif
