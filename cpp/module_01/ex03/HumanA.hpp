
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"
#include "colors.hpp"

class HumanA
{

public:
	HumanA(std::string name, Weapon &w);
	~HumanA();

	void setWeapon(Weapon &w);
	void attack( void );

private:
	HumanA();
	std::string _name;
	Weapon *_weapon;
};

#endif