#include "Form.hpp"

Form::Form()
{
	_name = "";
	_signed = 0;
	_sign_grade = 0;
	_exec_grade = 0;
}

Form(Form &f)
{
    (*this) = f;
}

Form 		&operator=(Form &f)
{
    _name = f.getName();
	_signed = f.getSigned();
	_sign_grade = f.getSignGrade();
	_exec_grade = f.getExecGrade();
}

Form::~Form()
{

}

std::string	Form::getName()
{
    return _name;
}

bool		Form::getSigned()
{
    return _signed;
}

int			Form::getSignGrade()
{
    return _sign_grade;
}

int			Form::getExecGrade()
{
    return _exec_grade;
}

void        Form::gradeValidator(int g)
{
	if (g < Bureaucrat::max_grade)
		throw GradeTooHighException();
	if (g > Bureaucrat::min_grade)
		throw GradeTooLowException();
}