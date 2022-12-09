
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

void Bureaucrat::grade()
{
	if (_grade > Bureaucrat::max_grade)
		_grade--;
	else
		throw GradeTooHighException().setName(_name);
}

void Bureaucrat::degrade()
{
	if (_grade < Bureaucrat::min_grade)
		_grade++;
	else
		throw GradeTooLowException().setName(_name);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
	out << "\x1b[33m" << value.getName() << "\x1b[0m" << ", bureaucrat grade " << value.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		if (f.isSigned())
			std::cout << "\x1b[33m" << this->getName() << "\x1b[0m" 
				<< " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << "\x1b[33m" << this->getName() << "\x1b[0m" 
			<< " couldn’t sign " << "\x1b[36m" << f.getName() << "\x1b[0m"
			<< " because their grade is to low" << std::endl;
	}
}

