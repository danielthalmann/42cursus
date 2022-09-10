#include "PresidentialPardonForm.hpp"

#define CLASSNAME "PresidentialPardonForm"

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential", 25, 5)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_target = "presidential";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("presidential", 25, 5), _target(target)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct with value " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &form) : Form(form)
{
	(*this) = (form);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	(void) form;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "execute " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	executeValidator(executor);

	std::cout << "\x1b[34m" << _target << "\x1b[0m" << " has been forgiven by Zaphod Beeblebrox" << std::endl;

}

