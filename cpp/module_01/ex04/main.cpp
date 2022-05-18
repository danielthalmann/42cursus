
#include <iostream>
#include <fstream>
#include "colors.hpp"
#include "SearchReplace.hpp"

int help (char **argv)
{
	std::cout << "Le nombre d'argument est incorrect !" << std::endl;
	std::cout << "Utilise la syntaxe suivante :" << std::endl << std::endl;
	std::cout << ANSI_COLOR_RED << "$> " << ANSI_COLOR_RESET << argv[0] << " fichier recherche remplace" << std::endl << std::endl;
	
	std::cout << ANSI_COLOR_GREEN << "fichier   " << ANSI_COLOR_RESET << " : Nom du fichier à traiter" << std::endl;
	std::cout << ANSI_COLOR_GREEN << "recherche " << ANSI_COLOR_RESET << " : texte à rechercher dans le fichier" << std::endl;
	std::cout << ANSI_COLOR_GREEN << "remplace  " << ANSI_COLOR_RESET << " : texte qui remplacera le contenu recherché" << std::endl;
	std::cout << std::endl;

	return (1);
}

int err_opening (char **argv)
{
	std::cout << "Impossible d'ouvrir le fichier '" << argv[1] << "'" << std::endl;
	return (1);
}

int main ( int argc, char **argv )
{
	if (argc != 4)
		return (help(argv));
	
	SearchReplace sr; 

	try
	{
		sr.setFileName(argv[1]);
		sr.setSearch(argv[2]);
		sr.setReplace(argv[3]);
	}
	catch(SearchReplace::OpenFileException &e)
	{
	      std::cout << "OpenFileException caught" << std::endl;
		std::cout << e.what() << std::endl;
		return (1);
	}

	sr.replace();
	
	return (0);
}
