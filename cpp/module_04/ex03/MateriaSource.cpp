#include "MateriaSource.hpp"

#define CLASSNAME "MateriaSource"

MateriaSource::MateriaSource()
{
	_length = 0;
	for (int i = 0; i < MateriaSource::max_size; i++)
	{
		this->_materials[i] = NULL;
	}

	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &materiasource)
{
	_length = 0;
	for (int i = 0; i < MateriaSource::max_size; i++)
	{
		this->_materials[i] = NULL;
	}
	*this = materiasource;
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiasource)
{
	for (int i = 0; i < MateriaSource::max_size; i++)
	{
		this->_materials[i] = materiasource._materials[i];
	}
	_length = materiasource._length;
	
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* mat)
{
	if (_length < MateriaSource::max_size)
	{
		this->_materials[_length] = mat;
		_length++;
	}
	else 
	{
		std::cout << "\x1b[32m" << "learn limit reached" << "\x1b[0m" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MateriaSource::max_size; i++)
	{
		if (_materials[i]->getType() == type)
		{
			return _materials[i]->clone();
		}
	}

	return NULL;
}
