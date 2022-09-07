#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
public:
				Form();
	virtual 	~Form();
				Form(Form &f);
	Form 		&operator=(Form &f);

	std::string	getName();
	bool		isSigned();
	int			getSignGrade();
	int			getExecGrade();

	void		beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception	{
		const char *what () const throw () {
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception	{
		const char *what () const throw () {
			return ("Grade too low");
		}
	};

private:
	
	void        gradeValidator(int g);

	std::string	_name;
	bool		_signed;
	int			_sign_grade;
	int			_exec_grade;

};

#endif