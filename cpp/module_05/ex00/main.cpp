
#include <iostream>
#include "Bureaucrat.hpp"

int main ( )
{
	try{
		std::cout << "\x1b[32m" << "Bureaucrat" << "\x1b[0m" << " with grade 5" << std::endl;
		Bureaucrat lambique("lambique", 5);
		for (int i = 4; i > -2; i--)
		{
			std::cout << "\x1b[32m" << "Bureaucrat.grade()" << "\x1b[0m" << std::endl;
			lambique.grade();
			std::cout << lambique;
		}
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
		std::cout << "\x1b[32m" << "Bureaucrat" << "\x1b[0m" << " with grade -1" << std::endl;
		Bureaucrat bob("bob", -1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
    try{
		std::cout << "\x1b[32m" << "Bureaucrat" << "\x1b[0m" << " with grade 155" << std::endl;
		Bureaucrat bobette("bobette", 155);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		std::cout << "\x1b[32m" << "Bureaucrat" << "\x1b[0m" << " with grade 5" << std::endl;
		Bureaucrat sidonie("sidonie", 146);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "\x1b[32m" << "Bureaucrat.grade()" << "\x1b[0m" << std::endl;
			sidonie.degrade();
			std::cout << sidonie;
		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
