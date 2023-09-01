#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <set>
# include <vector>

class Span
{
	private:
		size_t max_size;
		std::set<int> numbers;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(Span const &copy);
		Span	&operator=(Span const &copy);
		template<typename Iter>
		Span(Iter begin, Iter end) {
			max_size = end - begin;
			std::cout << "max_size: " << max_size << std::endl;
			numbers = std::set<int>(begin, end);
		}

		class NoMoreNums: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return("ERROR: No more nums are possible\n");
				}
		};

		class NotTwo: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return("ERROR: No possible to calculate, need two numbers\n");
				}
		};

		void addNumber(int num);

		int shortestSpan();
		int longestSpan();
		void print();
};

#endif
