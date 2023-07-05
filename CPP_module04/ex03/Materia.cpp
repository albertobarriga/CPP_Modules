#include "Materia.hpp"

// AMATERIA CLASS

AMateria::AMateria() {

}

AMateria::AMateria(std::string const & type) : _type(type){

}

AMateria::~AMateria() {

}

AMateria::AMateria(AMateria const &copy) {
	this->_type = copy._type;
	return *this;
}

AMateria & AMateria::operator=(AMateria const &copy) {
	
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMaterial::use(ICharacter& target) {
	if (this->_type == "ice")
		std::cout << "Ice: '* shoots an ice bolt at " << target.getname() << "*'" << std::endl;
	else if (this->_type == "cure")
		std::cout << "Cure: '* heals " << target.getname() << "'s wounds *'" << std::endl;
}

// ICE CLASS

Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}

Ice	& Ice::operator=(Ice const &copy) {
	this->_type = copy.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

// CURE CLASS 

Cure::Cure() : AMATERIA("cure") {

}

Cure::~Cure() {

}

Cure	& Cure::operator=(Cure const &copy) {
	this->_type = copy.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}