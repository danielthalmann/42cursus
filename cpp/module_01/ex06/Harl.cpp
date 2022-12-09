#include "Harl.hpp"

Harl::Harl()
{
	_levels[0].fn = &Harl::debug;
	_levels[1].fn = &Harl::info;
	_levels[2].fn = &Harl::warning;
	_levels[3].fn = &Harl::error;

	_levels[0].name = "DEBUG";
	_levels[1].name = "INFO";
	_levels[2].name = "WARNING";
	_levels[3].name = "ERROR";
}

Harl::~Harl()
{

}

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
	int level_found = 0;
	for (int i = 0; i < 4; i++)
	{
		if (level_found || _levels[i].name.compare(level) == 0)
		{
			level_found = 1;
			(this->*(_levels[i].fn))();
		}
	}
	if (!level_found)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}
