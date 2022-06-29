#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name	("ClapTrpap"),
	_hit	(10),
	_energy	(10),
	_damage	(0)
{

}

ClapTrap::ClapTrap(const std::string name, const int hit, const int energy, const int damage) :
	_name	(name),
	_hit	(hit),
	_energy	(energy),
	_damage	(damage)
{

}

ClapTrap::ClapTrap(const ClapTrap &claptrap) :
	_name	(claptrap._name),
	_hit	(claptrap._hit),	
	_energy	(claptrap._energy),
	_damage	(claptrap._damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	_name = clapTrap._name;
	_hit = clapTrap._hit;
	_energy = clapTrap._energy;
	_damage = clapTrap._damage;

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit > 0)
	{
		if (_energy > 0)
		{
			std::cout << _name << " attacks " << target << ", causing " << _damage << " point of domage!" << std::endl;
			_energy--;
		}
		else
			std::cout << _name << " can't attack, no more energy" << std::endl;

	}
	else
		std::cout << _name << " can't attack, is dead" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		std::cout << _name << " repaire, " << amount << " point of live!" << std::endl;
		_hit += amount;
		_energy--;
	}
	else
		std::cout << _name << " can't repaire, no more energy" << std::endl;

}

