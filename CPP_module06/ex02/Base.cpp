# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::Base() {

}

Base::~Base() {

}

Base	*generate(void) {
	
	switch (rand() % 3)
	{
		case (0):
			return(new(A));
		case (1):
			return(new(B));
		default:
			return(new(C));
	};
}

void	identify(Base	*p) {
	if (dynamic_cast<A *>(p))
		std::cout << "this pointer is A object" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "this pointer is B object" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "this pointer is C object" << std::endl;
	else
		std::cout << "this pointer is NULL" << std::endl;
}

void	identify(Base	&p) {
	Base	point_try;

	try {
		point_try = dynamic_cast<A &>(p);
		std::cout << "this reference is A object" << std::endl;
		return;
	}
	catch (std::bad_cast) {

	}
	try {
		point_try = dynamic_cast<B &>(p);
		std::cout << "this reference is B object" << std::endl;
		return;
	}
	catch (std::bad_cast) {

	}
	try {
		point_try = dynamic_cast<C &>(p);
		std::cout << "this reference is C object" << std::endl;
		return;
	}
	catch (std::bad_cast) {

	}
	std::cout << "this pointer is not A, B or C" << std::endl;

}