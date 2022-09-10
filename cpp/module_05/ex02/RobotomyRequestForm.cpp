#include "RobotomyRequestForm.hpp"

#define CLASSNAME "RobotomyRequestForm"

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy", 72, 45)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_target = "robotomy";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("robotomy", 72, 45), _target(target)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct with value " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &form) : Form(form)
{
	(*this) = (form);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	(void) form;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "execute " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	executeValidator(executor);

	std::cout << "Bzzz bzzz ping pllogg twisszz" << std::endl;
	if (std::rand() % 2)
		std::cout << "\x1b[34m" << _target << "\x1b[0m" << " has been successfully robotomized" << std::endl;
	else
		std::cout << "\x1b[31m" << "Operation failed" << "\x1b[0m" << std::endl;
}

