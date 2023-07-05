#ifndef MATERIA_HPP
#define MATERIA_HPP

# include <iostream>

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		~AMateria();
		AMateria(AMateria const &copy);

		std::string const & getType() const; //Returns the materia type
		AMateria	&operator=(AMateria const &copy);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

class Ice: public AMateria
{
	private:

	public:
		Ice();
		~Ice();
		Ice(Ice const &copy);
		Ice	&operator=(Ice const &copy);

		AMateria* clone() const;
};

class Cure: public AMateria
{
	private:

	public:
		Cure();
		~Cure();
		Cure(Cure const &copy);
		Cure	&operator=(Cure const &copy);

		AMateria* clone() const;
};

#endif


#endif


#endif
