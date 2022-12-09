
#include <iostream>
#include <iomanip>
#include "colors.hpp"
#include "Harl.hpp"

int help (char **argv)
{
	std::cout << "Le nombre d'argument est incorrect !" << std::endl;
	std::cout << "Utilise la syntaxe suivante :" << std::endl << std::endl;
	std::cout << ANSI_COLOR_RED << "$> " << ANSI_COLOR_RESET << argv[0] << " loglevel" << std::endl << std::endl;
	
	std::cout << ANSI_COLOR_GREEN << "loglevel   " << ANSI_COLOR_RESET << " : niveau du log." << std::endl;
	std::cout << "              Les valeurs autorisé sont ";
	std::cout << ANSI_COLOR_BLUE << "DEBUG, INFO, WARNING ou ERROR."  << ANSI_COLOR_RESET << std::endl << std::endl;

	return (1);
}

int main ( int argc, char **argv )
{

	Harl harl;

	if ( argc != 2 )
	{
		return (help(argv));
	}
	harl.complain(argv[1]);

	return (0);
}
