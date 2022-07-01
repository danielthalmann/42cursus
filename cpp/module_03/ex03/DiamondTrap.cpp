#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ClapTrap("default DiamondTrap")
{
    std::cout << ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << "Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
    this->_name = name;
	this->_hit = FragTrap::_hit;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;

    std::cout<< ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << "Constructor with name called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap): ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
    std::cout<< ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << "Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << "Destructor called" << std::endl;
}
    
DiamondTrap &DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	this->_name = diamondTrap._name + "_clap_trap";
	this->_hit = diamondTrap._hit;
	this->_energy = diamondTrap._energy;
	this->_damage = diamondTrap._damage;
    this->_guard = diamondTrap._guard;

    std::cout<< ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << DiamondTrap::_name << " call high Five" << std::endl;

    return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout<< ANSI_COLOR_GREEN << "DiamondTrap " << ANSI_COLOR_RESET << " ClapTrap::_name " << ClapTrap::_name << " DiamondTrap::_name " << DiamondTrap::_name << std::endl;
}