#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>
# include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe	&operator=(PmergeMe const &input);

		int 	fill(char **argv);
		void	mergesort();
		std::vector<int> merge_algtm(std::vector<int> vect);
};

#endif
