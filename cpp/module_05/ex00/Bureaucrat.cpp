
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n), _grade(g)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(Bureaucrat &b)
{
	(*this) = b;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &b)
{
	_grade = b._grade;
	_name = b._name;

	return (*this);
}

