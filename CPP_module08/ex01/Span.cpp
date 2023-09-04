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
	int dist = INT_MAX;
	int temp = INT_MAX;
	std::vector<int> nums(numbers.begin(), numbers.end());

	if (nums.size() <= 1)
		throw(NotTwo());

	for (int i = 0; nums[i] != *(nums.end() - 1); i++) {
		if (i != 0)
			temp = nums[i] - nums[i - 1];
		if (temp < dist)
			dist = temp;
	}
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

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t i = (size_t)std::distance(begin, end);
	if (max_size < i)
		throw(NoMoreNums());
	this->numbers.insert(begin, end);
}

// void Span::print() {
// 	std::set<int>::iterator ite;
// 	for (ite = numbers.begin(); ite != numbers.end(); ite++) {
// 		std::cout << *ite << ", "; 
// 	}
// 	std::cout << std::endl;
// }

