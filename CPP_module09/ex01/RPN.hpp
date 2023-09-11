#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_nums;
	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN	&operator=(RPN const &copy);

		bool	calculate(std::string const &input);
		bool	result();
};

#endif
