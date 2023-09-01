#include "Span.hpp"
#include <limits>


Span::Span() {

}

Span::Span(unsigned int N) {
	max_size = N;
}
Span::~Span(){

}

Span::Span(Span const &copy): max_size(copy.max_size), numbers(copy.numbers) {

}

Span	&Span::operator=(Span const &copy) {
	this->max_size = copy.max_size;
	this->numbers = copy.numbers;
	return(*this);
}

void Span::addNumber(int num)
{
	if (numbers.size() < max_size)
	{
		numbers.insert(num);
	}
	else
		throw (NoMoreNums());
}

int Span::shortestSpan() {
	std::vector<int> nn(numbers.begin(), numbers.end());
	for (size_t i=0; i < nn.size(); i++)
		std::cout << "nn[" << i << "]: " << nn[i] << std::endl;
	std::set<int>::iterator ite;
	int dist = INT_MAX;
	int temp = INT_MAX;
	if (numbers.size() <= 1)
		throw(NotTwo());
	int i = 0;
	for (ite = numbers.begin(); ite != numbers.end(); ite++) {
		if (*(ite) != *numbers.begin())
			temp = *ite - *(--ite++);
		if (temp < dist)
			dist = temp;
		std::cout << "dist: " << dist << ", i: " << i++ << ", n: " << *ite << std::endl;
	}
	std::cout << "Sale bucle" << std::endl;
	return (dist);
}

int Span::longestSpan() {
	std::set<int>::iterator ite;
	int dist;

	if (numbers.size() <= 1)
		throw(NotTwo());
	dist = *(--(numbers.end())) - *numbers.begin();
	return (dist);

}

void Span::print() {
	std::set<int>::iterator ite;
	for (ite = numbers.begin(); ite != numbers.end(); ite++) {
		std::cout << *ite << ", "; 
	}
	std::cout << std::endl;
}

