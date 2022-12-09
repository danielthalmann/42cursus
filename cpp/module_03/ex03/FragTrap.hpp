#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "colors.hpp"
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string name);
    FragTrap(const FragTrap& fragTrap);
    virtual ~FragTrap();
    FragTrap &operator=(const FragTrap& fragTrap);
	
	void highFiveGuys(void);
};

#endif