#include "iter.hpp"
#include <iostream>

int square(int num)
{
	return (num * num);
}

void print(int *num, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << num[i] << std::endl;
}

int main()
{
	int	a[4] = {2, 5, 8, 9};
	print(a, 4);
	std::cout << std::endl;
	::iter(a, 4, square);
	print(a, 4);
}