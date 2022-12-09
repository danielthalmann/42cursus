#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
public:
				Form();
				Form(std::string name, int signGrade, int execGrade);
				Form(Form &f);
	virtual 	~Form();
	Form 		&operator=(Form &f);

	std::string	getName() const;
	bool		isSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	virtual Form		*clone(std::string target) const = 0;
	virtual const std::string	getType() const = 0;


	void		beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class ExecutionNotAllowException : public std::exception	{
		const char *what () const throw () {
			return ("The grade is too low to execute form");
		}
	};

protected:

	int			gradeValidator(int g);
	void		executeValidator(Bureaucrat const &b) const;

private:
	
	std::string	_name;
	bool		_signed;
	int			_sign_grade;
	int			_exec_grade;

};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif