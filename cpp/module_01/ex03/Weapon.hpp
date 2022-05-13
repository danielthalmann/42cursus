

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();

	void setType(std::string t);
	std::string getType( void );

private:
	std::string _type;
};

#endif