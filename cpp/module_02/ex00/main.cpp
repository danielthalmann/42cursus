
#include <iostream>
#include "colors.hpp"


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
