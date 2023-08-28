#include "Serializer.hpp"

int main () {
	Data *data = new Data; //Allocation of a data in memory

	uintptr_t loc = Serializer::serialize(data); //Convert the location to a uint

	Data *data_loc = Serializer::deserialize(loc); // Passing Data from uint

	std::cout << "Data: " << data << std::endl;
	std::cout << "Data name: " << data->getName() << std::endl;
	std::cout << "loc: " << loc << std::endl;
	std::cout << "Data loc: " << data_loc << std::endl;
	std::cout << "data loc name: " << data_loc->getName() << std::endl;
}