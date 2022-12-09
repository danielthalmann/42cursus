#include "Character.hpp"

#define CLASSNAME "Character"

Character::Character() : _name("character")
{
	_length = 0;
	for (int i = 0; i < Character::max_size; i++)
	{
		this->_materials[i] = NULL;
	}
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Character::Character(std::string name) : _name(name)
{
	Character();
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Character::Character(Character &character)
{
	(void) character;
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Character::~Character()
{
	for (int i = 0; i < Character::max_size; i++)
	{
		if (this->_materials[i])
			delete this->_materials[i];
	}

	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Character &Character::operator=(const Character &character)
{
	for (int i = 0; i < Character::max_size; i++)
	{
		if (this->_materials[i])
			delete this->_materials[i];
		this->_materials[i] = character._materials[i];
	}
	_length = character._length;
	_name = character._name;
	
	#ifdef DEBUG
	std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	return (*this);
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (_length < Character::max_size)
	{
		this->_materials[_length] = m;
		_length++;
	}
	else 
	{
		std::cout << "\x1b[32m" << "equip limit reached" << "\x1b[0m" << std::endl;
	}

}

void Character::unequip(int idx)
{
	if (idx < _length && idx >= 0)
	{
		_length--;
		for (int i = Character::max_size - 1; i > idx; i--)
		{
			this->_materials[i - 1] = this->_materials[i + 1];
		}	
		this->_materials[_length] = NULL;
	}
	else 
	{
		std::cout << "\x1b[32m" << "out of limit" << "\x1b[0m" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < Character::max_size && idx >= 0)
	{
		if (this->_materials[idx] != NULL)
		{
			this->_materials[idx]->use(target);
		}
	}
}
