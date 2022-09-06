#include "Cat.hpp"

#define CLASSNAME "Cat"

Cat::Cat()
{
	_brain = new Brain();

	std::string *ideas = _brain->getIdeas();
	for (int i = 0; i < Brain::sizeOfIdeas; i++)
		ideas[i] = "fish";

	_type = CLASSNAME;
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Cat::Cat(Cat &cat) : AAnimal (cat)
{
	_type = cat._type;
	*(_brain) = *(cat._brain);
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

AAnimal	&Cat::operator=( const AAnimal &other )
{
	_type = other.getType();
	*(_brain) = *(other.getBrain());
	std::cout << "\x1b[32m" << "Operator Equal AAnimal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);	
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat._type;
	*(_brain) = *(cat._brain);
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu !" << std::endl;
}

std::string Cat::getType(void) const
{
	return (_type);
}


Brain *Cat::getBrain(void) const
{
	return (_brain);
}
