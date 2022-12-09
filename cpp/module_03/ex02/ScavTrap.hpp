#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "colors.hpp"
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap& scavTrap);
    virtual ~ScavTrap();
    ScavTrap &operator=(const ScavTrap& scavTrap);
	
    void attack(const std::string& target);
	void guardGate(void);

protected:
    bool   _guard;

};

#endif