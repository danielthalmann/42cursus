
#include <iostream>
#include <iomanip>
#include "Harl.hpp"

int main ( void )
{

	Harl harl;

	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("OTHER");

	return (0);
}
