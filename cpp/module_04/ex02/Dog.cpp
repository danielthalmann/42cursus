#include "Dog.hpp"

#define CLASSNAME "Dog"

Dog::Dog()
{
	_brain = new Brain();
	_type = CLASSNAME;

	std::string *ideas = _brain->getIdeas();
	for (int i = 0; i < Brain::sizeOfIdeas; i++)
		ideas[i] = "bone";

	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog::Dog(Dog &dog) : AAnimal(dog)
{
	_type = dog._type;
	*(_brain) = *(dog._brain);
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	*(_brain) = *(dog._brain);
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

AAnimal	&Dog::operator=( const AAnimal &other )
{
	_type = other.getType();
	*(_brain) = *(other.getBrain());
	std::cout << "\x1b[32m" << "Operator Equal AAnimal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);	
}

void Dog::makeSound(void) const
{
	std::cout << "Wouafff !" << std::endl;
}

std::string Dog::getType(void) const
{
	return (_type);
}

Brain *Dog::getBrain(void) const
{
	return (_brain);
}
