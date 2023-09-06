#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::cout << std::endl << "print the up to down: " << std::endl << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);



	std::cout << std::endl << "Begin of another container to check : " << std::endl << std::endl;
	std::list<int> mlist;
	mlist.push_front(5);
	mlist.push_front(17);
	std::cout << "top: " << mlist.front() << std::endl;
	mlist.pop_front();
	std::cout << "size: " << mlist.size() << std::endl;
	mlist.push_front(3);
	mlist.push_front(5);
	mlist.push_front(737);
	//[...]
	mlist.push_front(0);
	std::cout << std::endl << "print the up to down: " << std::endl << std::endl;


	std::list<int>::iterator iter;
	for (iter = --mlist.end(); iter != --mlist.begin(); iter--)
	{
		std::cout << *(iter) << std::endl;
	}
	// std::stack<int> s(mlist);
	return 0;
}