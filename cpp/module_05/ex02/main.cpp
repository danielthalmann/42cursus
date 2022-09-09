
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main ( )
{

	Bureaucrat bob("bob", 42);
	Bureaucrat bobette("bobette", 43);

	// Form form();

	Form *shrubbery = NULL;
	shrubbery = new ShrubberyCreationForm();
	
	std::cout << bob;
	std::cout << *shrubbery;

	bob.signForm(*shrubbery);
	
	std::cout << bobette;
	std::cout << *shrubbery;

	bobette.signForm(*shrubbery);
	bobette.executeForm(*shrubbery);

	delete shrubbery;

	return (0);
}
