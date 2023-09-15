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
		if (num < 0)
		{
			std::cerr << "Error" << std::endl;
			return(1);
		}
		_vector.push_back(num);
		_list.push_back(num);
	}
	return 0;
}

std::vector<int> PmergeMe::merge_algtm(std::vector<int> vect)
{
	// insert algorithm
	if (vect.size() < 20)
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
	//merge algorithm
	std::vector<int>::iterator mid =  vect.begin() + (vect.size() / 2);
	std::vector<int> left(vect.begin(), mid);
	std::vector<int> right(mid, vect.end());

	left = PmergeMe::merge_algtm(left);
	right = PmergeMe::merge_algtm(right);

	std::vector<int> result(vect.size());
	std::merge(left.begin(), left.end(), right.begin(), right.end(), result.begin());

	return result;
}

std::list<int> PmergeMe::merge_algtm_lst(std::list<int> lst)
{
	// insert algorithm
	if (lst.size() < 20)
	{
		for (std::list<int>::iterator i = ++lst.begin(); i != lst.end(); i++)
		{
			int key = *i;
			std::list<int>::iterator j = i;
			std::list<int>::iterator k = i;
			j--;
			while (k != lst.begin() && *j > key)
			{
				*k = *j;
				j--;
				k--;
			}
			*k = key;
		}
		return lst;
	}
	//merge algorithm
	std::list<int>::iterator mid =  lst.begin();
	std::advance(mid,lst.size() / 2);
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());

	left = PmergeMe::merge_algtm_lst(left);
	right = PmergeMe::merge_algtm_lst(right);

	std::list<int> result(lst.size());
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
	double vect_duration = static_cast<double>((end_vect_time - start_vect_time) * 1.e6) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 3000 elements with std::vector : " << vect_duration << " us" << std::endl;


	std::clock_t start_list_time = std::clock();

	// //algoritmo de ordenación
	_list = merge_algtm_lst(_list);

	// std::cout << "After list: ";
	// for (std::list<int>::iterator i = _list.begin(); i != _list.end(); i++)
	// {
	// 	std::cout << *i << " ";
	// }
	std::clock_t end_list_time = std::clock();
	// double list_duration = static_cast<double>(end_list_time - start_list_time) / CLOCKS_PER_SEC;
	double list_duration = static_cast<double>((end_list_time - start_list_time) * 1.e6) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 3000 elements with std::list : " << list_duration << " us" << std::endl;

	
}