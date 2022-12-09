
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce( void );

private:
	std::string _name;

};

#endif