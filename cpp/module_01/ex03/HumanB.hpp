
#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"
#include "colors.hpp"

class HumanB
{

public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon &w);
	void attack( void );

private:
	HumanB();
	std::string _name;
	Weapon *_weapon;
};

#endif