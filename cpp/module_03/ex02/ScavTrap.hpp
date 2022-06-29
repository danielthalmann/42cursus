#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "colors.hpp"
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string name, const int hit = 100, const int energy = 50, const int damage = 20);
    ScavTrap(const ScavTrap& clapTrap);
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap& scavTrap);

	void guardGate(void);

};

#endif