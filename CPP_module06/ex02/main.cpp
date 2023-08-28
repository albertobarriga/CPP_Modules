# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main () {
	std::srand(std::time(0)); //I need to put the seed in the main to generate only one.
	for (int i = 0; i < 5; i++)
	{
		Base *test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
}