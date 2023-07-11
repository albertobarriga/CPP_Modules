#include "Materia.hpp"
#include "Character.hpp"

// AMATERIA CLASS

AMateria::AMateria() {

}

AMateria::AMateria(std::string const & type) : _type(type){

}

AMateria::~AMateria() {

}

AMateria::AMateria(AMateria const &copy) {
	this->_type = copy._type;
}

AMateria & AMateria::operator=(AMateria const &copy) {
	this->_type = copy._type;
	return *this;
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	if (this->_type == "ice")
		std::cout << "Ice: '* shoots an ice bolt at " << target.getName() << "*'" << std::endl;
	else if (this->_type == "cure")
		std::cout << "Cure: '* heals " << target.getName() << "'s wounds *'" << std::endl;
}

// ICE CLASS

Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}

Ice::Ice(Ice const &copy) {
	this->_type = copy.getType();
}

Ice	& Ice::operator=(Ice const &copy) {
	this->_type = copy.getType();
	return *this;
}

AMateria* Ice::clone() const {
	return (new Ice());
}

// CURE CLASS 

Cure::Cure() : AMateria("cure") {

}

Cure::~Cure() {

}

Cure::Cure(Cure const &copy) {
	this->_type = copy.getType();
}

Cure	& Cure::operator=(Cure const &copy) {
	this->_type = copy.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return (new Cure());
}