#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "colors.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap& diamondTrap);
    virtual ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap& diamondTrap);

	void attack(const std::string &target);
	void whoAmI(void);


protected:
    std::string _name;

};

#endif