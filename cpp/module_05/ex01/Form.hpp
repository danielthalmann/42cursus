#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
public:
				Form();
	virtual 	~Form();
				Form(std::string name, int signGrade, int execGrade);
				Form(Form &f);
	Form 		&operator=(Form &f);

	std::string	getName() const;
	bool		isSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void		beSigned(const Bureaucrat &b);

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
	
	int        gradeValidator(int g);

	std::string	_name;
	bool		_signed;
	int			_sign_grade;
	int			_exec_grade;

};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif