
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void trait(Bureaucrat &b)
{
	std::cout << b;

	Form *form[3];
	form[0] = new ShrubberyCreationForm("tree"); 
	form[1] = new RobotomyRequestForm("daniel"); 
	form[2] = new PresidentialPardonForm("harold");
	
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << *(form[i]);
	}

	std::cout << "-------------------------------" << std::endl;

	for (size_t i = 0; i < 3; i++)
	{
		try {
			std::cout << "\x1b[33m" << b.getName() << "\x1b[0m" << " try to sign form " << form[i]->getName() << std::endl;
			b.signForm(*(form[i]));
		}
		catch( std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "-------------------------------" << std::endl;

	for (size_t i = 0; i < 3; i++)
	{
		try {
			if (i == 1) {
				//std::cout << "\x1b[33m" << b.getName() << "\x1b[0m" << " try to execute form " << form[i]->getName() << std::endl;
				b.executeForm(*(form[i]));
			}

			//std::cout << "\x1b[33m" << b.getName() << "\x1b[0m" << " try to execute form " << form[i]->getName() << std::endl;
			b.executeForm(*(form[i]));
		}
		catch( std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	delete form[0];
	delete form[1];
	delete form[2];

	std::cout << "-------------------------------" << std::endl;
	std::cout << std::endl << std::endl;

}

int main ( )
{

	Bureaucrat bob("bob", 42);
	Bureaucrat bobette("bobette", 43);
	Bureaucrat jerome("jerome", 43);

	trait(bob);
	trait(bobette);
	trait(jerome);

	return (0);
}
