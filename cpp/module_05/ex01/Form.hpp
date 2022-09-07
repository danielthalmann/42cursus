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
	bool		getSigned();
	int			getSignGrade();
	int			getExecGrade();

	class GradeTooHighException : public std::exception	{
	};

	class GradeTooLowException : public std::exception	{
	};

private:
	
	void        gradeValidator(int g);

	std::string	_name;
	bool		_signed;
	int			_sign_grade;
	int			_exec_grade;

};

#endif