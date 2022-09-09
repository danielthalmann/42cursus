#include "Form.hpp"

Form::Form()
{
	_name = "";
	_signed = false;
	_sign_grade = 0;
	_exec_grade = 0;
}

Form::Form(Form &f)
{
    (*this) = f;
}

Form 		&Form::operator=(Form &f)
{
    _name = f.getName();
	_signed = f.isSigned();
	_sign_grade = f.getSignGrade();
	_exec_grade = f.getExecGrade();

	return (*this);
}

Form::~Form()
{

}

std::string	Form::getName() const
{
    return _name;
}

bool		Form::isSigned() const
{
    return _signed;
}

int			Form::getSignGrade() const
{
    return _sign_grade;
}

int			Form::getExecGrade() const
{
    return _exec_grade;
}

void		Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _sign_grade) 
		_signed = true;
}

void        Form::gradeValidator(int g)
{
	if (g < Bureaucrat::max_grade)
		throw GradeTooHighException();
	if (g > Bureaucrat::min_grade)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << f.getName() << ", needed grade for signed " << f.getSignGrade() << std::endl;
	return out;
}