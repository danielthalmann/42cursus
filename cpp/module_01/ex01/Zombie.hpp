
#include <iostream>

class Zombie
{

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce( void );
	void setName( std::string name );

private:
	std::string _name;

};
