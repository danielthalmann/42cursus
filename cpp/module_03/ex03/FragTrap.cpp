#include "FragTrap.hpp"

 FragTrap::FragTrap() : ClapTrap()
{
	this->_name		= "FragTrap";
	
	if (this->_hit == 10)
		this->_hit = 100;
	if (this->_energy == 10)
		this->_energy = 100;
	if (this->_damage < 30)
		this->_damage = 30;
/*
	this->_hit		= 100;
	this->_energy	= 100;
	this->_damage	= 30;
*/
	std::cout<< ANSI_COLOR_CYAN << "FragTrap " << ANSI_COLOR_RESET << "Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_name		= name;

	if (this->_hit == 10)
		this->_hit = 100;
	if (this->_energy == 10)
		this->_energy = 100;
	if (this->_damage < 30)
		this->_damage = 30;
	std::cout<< ANSI_COLOR_CYAN << "FragTrap " << ANSI_COLOR_RESET << "Constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
	std::cout<< ANSI_COLOR_CYAN << "FragTrap " << ANSI_COLOR_RESET << "Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<< ANSI_COLOR_CYAN << "FragTrap " << ANSI_COLOR_RESET << "Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	this->_name		= fragTrap._name;
	this->_hit		= fragTrap._hit;
	this->_energy	= fragTrap._energy;
	this->_damage	= fragTrap._damage;

	std::cout << ANSI_COLOR_CYAN << "FragTrap " << ANSI_COLOR_RESET << "operator = called" << std::endl;

	return *this;
}

void FragTrap::highFiveGuys(void)
{
	std::cout<< ANSI_COLOR_MAGENTA << "ClapTrap " << ANSI_COLOR_RESET << _name << " call high Five" << std::endl;
}