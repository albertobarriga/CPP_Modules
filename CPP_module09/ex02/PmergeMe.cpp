#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const &copy): _vector(copy._vector), _list(copy._list) {

}

PmergeMe	&PmergeMe::operator=(PmergeMe const &input) {
	if(this != &input)
	{
		_vector = input._vector;
		_list = input._list;
	}
	return (*this);
}


int PmergeMe::fill(char **input)
{
	for (int i = 0; input[i]; i++)
	{
		int num = atoi(input[i]);
		_vector.push_back(num);
		_list.push_back(num);
	}
	return 0;
}

std::vector<int> PmergeMe::merge_algtm(std::vector<int> vect)
{
	// insert algorithm
	if (vect.size() < 200)
	{
		int len =  vect.size();
		for (int i = 0; i < len; i++)
		{
			int key = vect[i];
			int j = i - 1;
			while (j >= 0 && vect[j] > key)
			{
				vect[j + 1] = vect[j];
				j--;
			}
			vect[j + 1] = key;
		}
		return vect;
	}
	std::vector<int>::iterator mid =  vect.begin() + (vect.size() / 2);
	std::vector<int> left(vect.begin(), mid);
	std::vector<int> right(mid, vect.end());

	left = PmergeMe::merge_algtm(left);
	right = PmergeMe::merge_algtm(right);

	std::vector<int> result(vect.size());
	std::merge(left.begin(), left.end(), right.begin(), right.end(), result.begin());

	return result;


}


void	PmergeMe::mergesort() {
	std::cout << "Before: ";
	for (std::vector<int>::iterator i = _vector.begin(); i < _vector.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	std::clock_t start_vect_time = std::clock();

	//algoritmo de ordenación
	_vector = merge_algtm(_vector);

	std::clock_t end_vect_time = std::clock();
	std::cout << "After: ";
	for (std::vector<int>::iterator i = _vector.begin(); i < _vector.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	double vect_duration = static_cast<double>((end_vect_time - start_vect_time) * 10e6) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 3000 elements with std::vector : " << vect_duration << " us" << std::endl;


	// std::clock_t start_vect_time = std::clock();

	// //algoritmo de ordenación

	// std::clock_t end_vect_time = std::clock();
	// double stack_duration = static_cast<double>(end_vect_time - start_vect_time) / CLOCKS_PER_SEC;
	// std::cout << "Time to process a range of 3000 elements with std::stack : " << stack_duration << std::endl;

	
}