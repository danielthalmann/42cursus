#include "Intern.hpp"

#define CLASSNAME "Intern"

Intern::Intern()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_form[0] = new ShrubberyCreationForm(); 
	_form[1] = new RobotomyRequestForm(); 
	_form[2] = new PresidentialPardonForm();
}

Intern::Intern(Intern &intern)
{
	(*this) = (intern);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	for (int i = 0; i < Intern::form_length; i++)
		delete _form[i];
}

Intern &Intern::operator=(const Intern &intern)
{
	(void) intern;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}


Form *Intern::makeForm(std::string type, std::string target)
{
	for (int i = 0; i < Intern::form_length; i++)
	{
		if (_form[i]->getType() == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return _form[i]->clone(target);
		}
	}
	throw InvalidFormException();
}


