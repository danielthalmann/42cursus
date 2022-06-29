#include "ScavTrap.hpp"

 ScavTrap::ScavTrap()
{
	this->_name		= "ScavTrpap";
	this->_hit		= 100;
	this->_energy	= 50;
	this->_damage	= 20;
	std::cout<< ANSI_COLOR_CYAN << "ScavTrap " << ANSI_COLOR_RESET << "Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name, const int hit, const int energy, const int damage) 
{
	this->_name		= name;
	this->_hit		= hit;
	this->_energy	= energy;
	this->_damage	= damage;
	std::cout<< ANSI_COLOR_CYAN << "ScavTrap " << ANSI_COLOR_RESET << "Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap)
{
	this->_name		= scavtrap._name;
	this->_hit		= scavtrap._hit;
	this->_energy	= scavtrap._energy;
	this->_damage	= scavtrap._damage;
	std::cout<< ANSI_COLOR_CYAN << "ScavTrap " << ANSI_COLOR_RESET << "Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<< ANSI_COLOR_CYAN << "ScavTrap " << ANSI_COLOR_RESET << "Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->_name		= scavTrap._name;
	this->_hit		= scavTrap._hit;
	this->_energy	= scavTrap._energy;
	this->_damage	= scavTrap._damage;

	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout<< ANSI_COLOR_CYAN << "ScavTrap " << ANSI_COLOR_RESET << _name << " keep the gate" << std::endl;
}
