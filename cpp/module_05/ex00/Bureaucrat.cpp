
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Jon Doe"), _grade(Bureaucrat::min_grade)
{

}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n), _grade(g)
{
	gradeValidator(g);
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

void Bureaucrat::gradeValidator(int g)
{
	if (g < Bureaucrat::max_grade)
		throw GradeTooHighException().setName(_name);
	if (g > Bureaucrat::min_grade)
		throw GradeTooLowException().setName(_name);
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}
