#include "ScavTrap.hpp"

 ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name		= "ScavTrap";
	this->_hit		= 100;
	this->_energy	= 50;
	this->_damage	= 20;
	this->_guard	= false;
	std::cout<< ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << "Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->_name		= name;
	this->_hit		= 100;
	this->_energy	= 50;
	this->_damage	= 20;
	this->_guard	= false;
	std::cout<< ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << "Constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
	this->_guard	= scavtrap._guard;
	std::cout<< ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << "Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<< ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << "Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->_name		= scavTrap._name;
	this->_hit		= scavTrap._hit;
	this->_energy	= scavTrap._energy;
	this->_damage	= scavTrap._damage;
	this->_guard	= scavTrap._guard;

	std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << "operator = called" << std::endl;

	return *this;
}

void ScavTrap::guardGate(void)
{
	if (! this->_guard)
	{
		std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << _name << " guard the gate" << std::endl;
		this->_guard = true;
	}
	else
		std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << _name << " is already guarding the gate" << std::endl;
}

void ScavTrap::attack( std::string const & target )
{
	if (_hit > 0)
	{
		if (_energy > 0)
		{
			std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << _name << " attacks " << ANSI_COLOR_RED  << target << ANSI_COLOR_RESET << ", causing " << ANSI_COLOR_RED  << _damage << ANSI_COLOR_RESET << " point of domage!" << std::endl;
			_energy--;
		}
		else
			std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << _name << " can't attack, no more energy" << std::endl;
	}
	else
		std::cout << ANSI_COLOR_BLUE << "ScavTrap " << ANSI_COLOR_RESET << _name << " can't attack, is dead" << std::endl;

}
