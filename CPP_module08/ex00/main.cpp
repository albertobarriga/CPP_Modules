#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int>nums;

	for (int i = 0; i < 10; i++)
	{
		nums.push_back(i * 2);
	}

	try
	{
		std::cout << *easyfind(nums, 20) << "was find in the vector: " << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
		
}