#include "Data.hpp"

Data::Data() : _name("NOname") {

}

Data::~Data() {

}

Data::Data(Data const &copy) {
	(void)copy;
}

Data	&Data::operator=(Data const &copy) {
	this->_name = copy._name;
	return *this;
}

std::string Data::getName() const {
	return (this->_name);
}

