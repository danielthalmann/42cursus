#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
_name("ClapTrpap"),
_hit(10),
_energy(10),
_damage(0)
{

}

ClapTrap::ClapTrap(const ClapTrap &fixed) :
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &clapTrap)
{
	_name = clapTrap._name;
	_hit = clapTrap._hit;
	_energy = clapTrap._energy;
	_damage = clapTrap._damage;

	return *this;
}

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
