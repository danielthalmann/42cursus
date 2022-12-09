#include "Form.hpp"

#define CLASSNAME "Form"

Form::Form()
{
	
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_name = "";
	_signed = false;
	_sign_grade = Bureaucrat::min_grade;
	_exec_grade = Bureaucrat::min_grade;

}

Form::Form(std::string name, int signGrade, int execGrade)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Construct with values " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

	_name = name;
	_signed = false;
	_sign_grade = Form::gradeValidator(signGrade);
	_exec_grade = Form::gradeValidator(execGrade);
}

Form::Form(Form &f)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Copy Construct " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

    (*this) = f;
}

Form 		&Form::operator=(Form &f)
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Operator Equal " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif

    _name = f.getName();
	_signed = f.isSigned();
	_sign_grade = f.getSignGrade();
	_exec_grade = f.getExecGrade();

	return (*this);
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << "\x1b[32m" << "Destructor " << "\x1b[0m" << CLASSNAME << std::endl;
	#endif
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
	else
		throw GradeTooLowException();
}

int			Form::gradeValidator(int g)
{
	if (g < Bureaucrat::max_grade)
		throw GradeTooHighException();
	if (g > Bureaucrat::min_grade)
		throw GradeTooLowException();
	return g;
}
void		Form::executeValidator(Bureaucrat const &b) const
{
	if (!this->isSigned())
		throw ExecutionNotAllowException();

	if (b.getGrade() > this->getExecGrade()) 
		throw ExecutionNotAllowException();
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << "\x1b[36m" << f.getName() << "\x1b[0m" << ", form need grade " 
		<< f.getSignGrade() << " for signed and grade "
		<< f.getExecGrade() << " for execute" << std::endl;
	return out;
}