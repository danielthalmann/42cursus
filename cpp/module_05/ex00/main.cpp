
#include <iostream>
#include "Bureaucrat.hpp"

int main ( )
{
	
	try{
		Bureaucrat bob("bob", 5);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

    try{
		Bureaucrat bobette("bobette", 155);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
