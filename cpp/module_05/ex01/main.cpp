
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( )
{

	Bureaucrat bob("bob", 42);
	Bureaucrat bobette("bobette", 43);

	try{
		Form paperLow("paper", 151, 1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Form paperHight("paper", 150, -1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Form paper42("paper", 42, 24);
	
	std::cout << bob;
	std::cout << paper42;

	bob.signForm(paper42);
	

	std::cout << bobette;
	std::cout << paper42;

	bobette.signForm(paper42);

	return (0);
}
