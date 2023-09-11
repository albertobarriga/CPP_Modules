#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(RPN const &copy): _nums(copy._nums) {
}

RPN	&RPN::operator=(RPN const &copy) {
	if(this != &copy)
		_nums = copy._nums;
	return (*this);
}

bool	RPN::calculate(std::string const &input) {

	for (int i = 0; input[i]; i++)
	{
		if (isspace(input[i]))
			;
		else if (isnumber(input[i]))
			_nums.push(input[i] - '0');
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			if (_nums.size() < 2)
			{
				std::cout << "ERROR: CAN'T DO IT" << std::endl;
				return(1);
			}
			int x = _nums.top();
			_nums.pop();
			int y = _nums.top();
			_nums.pop();
			switch(input[i])
			{
				case '+':
					_nums.push(y + x);
					break;
				case '-':
					_nums.push(y - x);
					break;
				case '/':
					_nums.push(y / x);
					break;
				case '*':
					_nums.push(y * x);
					break;
			}
		}
		else
		{
			std::cout << "ERROR: BAD OPERATOR" << std::endl;
			return(1);
		}
	}
	return (0);
}

bool	RPN::result() {
	if (_nums.size() == 1)
	{
		std::cout << _nums.top() << std::endl;
		return 0;
	}
	else
	{
		std::cout << "ERROR: BAD SYNTAXIS" << std::endl;
		return 1;
	}
}
