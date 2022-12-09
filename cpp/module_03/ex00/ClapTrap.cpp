#include "ClapTrap.hpp"

 ClapTrap::ClapTrap() :
	_name	("ClapTrap"),
	_hit	(10),
	_energy	(10),
	_damage	(0)
{
	std::cout << "Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) :
	_name	(name),
	_hit	(10),
	_energy	(10),
	_damage	(0)
{
	std::cout << "Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) :
	_name	(claptrap._name),
	_hit	(claptrap._hit),	
	_energy	(claptrap._energy),
	_damage	(claptrap._damage)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	_name = clapTrap._name;
	_hit = clapTrap._hit;
	_energy = clapTrap._energy;
	_damage = clapTrap._damage;

	std::cout << ANSI_COLOR_MAGENTA << "ClapTrap " << ANSI_COLOR_RESET << "operator = called" << std::endl;

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit > 0)
	{
		if (_energy > 0)
		{
			std::cout << _name << " attacks " << ANSI_COLOR_RED  << target << ANSI_COLOR_RESET << ", causing " << ANSI_COLOR_RED  << _damage << ANSI_COLOR_RESET << " point of domage!" << std::endl;
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
	if (_hit > 0)
	{
		_hit -= amount;
		if (_hit < 0)
			_hit = 0;
		std::cout << _name << " take " << ANSI_COLOR_RED  << amount << ANSI_COLOR_RESET << " domage" << std::endl;
	}
	else
		std::cout << _name << " can't take damage, is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit > 0)
	{	
		if (_energy > 0)
		{
			std::cout << _name << " repaire, " << ANSI_COLOR_RED  << amount << ANSI_COLOR_RESET << " point of live!" << std::endl;
			_hit += amount;
			_energy--;
		}
		else
			std::cout << _name << " can't repaire, no more energy" << std::endl;
	}
	else
		std::cout << _name << " can't repaire, is dead" << std::endl;

}

void ClapTrap::info(void)
{
 	std::cout << std::endl << _name << " info's ->"
					   << " hit : " << ANSI_COLOR_BLUE << _hit << ANSI_COLOR_RESET 
					   << " energy : " << ANSI_COLOR_BLUE << _energy  << ANSI_COLOR_RESET 
					   << " damage : " << ANSI_COLOR_BLUE << _damage  << ANSI_COLOR_RESET << std::endl << std::endl;
}

