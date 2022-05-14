
#include <iostream>
#include <iomanip>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void initText(std::string type, std::string vname, std::string &var)
{
	std::cout << "J'ai initialisé la variable ";
	std::cout << ANSI_COLOR_GREEN << type << ANSI_COLOR_RESET << " ";
	std::cout << ANSI_COLOR_BLUE << vname << ANSI_COLOR_RESET ;
	std::cout << ", son adresse est \"" << ANSI_COLOR_RED << &var << ANSI_COLOR_RESET << "\"";
	std::cout << ", elle contient \"" << ANSI_COLOR_RED << var << ANSI_COLOR_RESET << "\"" << std::endl;

}

int main ( void )
{

	std::string myBrain("HI THIS IS BRAIN");

	initText("std::string ", "myBrain  ", myBrain);

	std::string* stringPTR = &myBrain;

	initText("std::string*", "stringPTR", *stringPTR);

	std::string& stringREF = myBrain;

	initText("std::string*", "stringPTR", stringREF);

	return (0);
}
