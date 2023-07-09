#include "IMateria.hpp"

IMateriaSource::~IMateriaSource() {

}

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->source[i] = NULL;
}

// MateriaSource::MateriaSource(std::string const &name) : _name(name) {
// 	for (int i = 0; i < 4; i++)
// 		this->source[i] = NULL;
// }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (this->source[i])
		{
			delete this->source[i];
			this->source[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy) {
	// for (int i = 0, i < 4, i++)
	// 	this->inventory[i] = NULL;
	*this = copy;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &copy)
{
	int i = 0;
	while (this->source[i])
	{
		delete this->source[i];
		this->source[i] = NULL;
	}
	for (i = 0; i < 4; i++)
	{
		if (copy.source[i])
			this->source[i] = copy.source[i];
	}

	return (*this);
}

	void MateriaSource::learnMateria(AMateria* m) {
		int i = 0;
		while (this->source[i])
			i++;
		this->source[i] = m->clone();
	}

	AMateria* MateriaSource::createMateria(std::string const & type) {
		for (int i = 0; (i < 4 && this->source[i] != NULL); i++)
		{
			if (this->source[i]->getType() == type)
				return (this->source[i]->clone());
		}
		return (0);
	}