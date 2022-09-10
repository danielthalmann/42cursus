#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
public:
	Intern();
	Intern(Intern &intern);
	virtual ~Intern();
	Intern &operator=(const Intern &intern);

	Form *makeForm(std::string type, std::string target);

	class InvalidFormException : public std::exception	{
		const char *what () const throw () {
			return ("Invalid form");
		}
	};


	const static int form_length = 3;
private:
	Form *_form[Intern::form_length];

};

#endif