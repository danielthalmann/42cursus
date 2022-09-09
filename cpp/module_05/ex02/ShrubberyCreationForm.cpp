#include "ShrubberyCreationForm.hpp"

#define CLASSNAME "ShrubberyCreationForm"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery", 145, 137)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	_target = "shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("shrubbery", 145, 137), _target(target)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct with value " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &form) : Form(form)
{
	(*this) = (form);
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	(void) form;
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "execute " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	executeValidator(executor);

	std::string filename = _target + "_shrubbery";

	std::ofstream file;
	file.open(filename.c_str(), std::ios_base::out|std::ios_base::trunc);
	
	if (!file.is_open())
	{
		throw ExecutionNotAllowException();
	}
	for (size_t i = 0; i < 3; i++)
	{
		file << "                                " << std::endl;
		file << "             ./#...( .          " << std::endl;
		file << "          ..##&&&&(( (.         " << std::endl;
		file << "       ..&&hOi%&#%&..;;(/       " << std::endl;
		file << "      &#hh.#@&@&&:(@%(,.;.O     " << std::endl;
		file << "     .:&@%&& O&&&%:&#/#((// *   " << std::endl;
		file << "      .&&&@##&&&#.#&&(#(%##(*   " << std::endl;
		file << "       '`    &&&:   `^   O  ´'. " << std::endl;
		file << "              &#:               " << std::endl;
		file << "          .&&&%&:;,,         	 " << std::endl;
		file << "                                " << std::endl;
	}
	
	file.close();

}

