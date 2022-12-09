
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void trait(Bureaucrat &b)
{
	Intern kevin;

	std::cout << b;

	Form *form[3];
	form[0] = kevin.makeForm("shrubbery creation", "tree"); 
	form[1] = kevin.makeForm("robotomy request", "daniel");
	form[2] = kevin.makeForm("presidential pardon", "harold"); 

	
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
	Intern kevin;

	Bureaucrat bob("bob", 150);
	Bureaucrat sidonie("sidonie", 70);
	Bureaucrat bobette("bobette", 42);
	Bureaucrat jerome("jerome", 2);

	try {
		Form *form = kevin.makeForm("strange", "not_pssible"); 
		(void) form;
	}
	catch( std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	trait(bob);
	trait(sidonie);
	trait(bobette);
	trait(jerome);

	return (0);
}
