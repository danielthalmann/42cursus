#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>

class Form;

class Bureaucrat
{

public:

	static const int	max_grade = 1;
	static const int	min_grade = 150;

	Bureaucrat();
	Bureaucrat(std::string n, int g);
	virtual ~Bureaucrat();
	Bureaucrat(Bureaucrat &b);
	Bureaucrat &operator=(Bureaucrat &b);

	std::string getName() const;
	int getGrade() const;

	void grade();
	void degrade();

	void signForm(Form &f);

	class GradeTooHighException : public std::exception
	{
	public:
		~GradeTooHighException() throw () {}
        GradeTooHighException &setName(const std::string &n)
        {
            _message = "Grade too high for '" + n + "'";
            return (*this);
        }
		const char *what () const throw () {
			return (_message.c_str());
		}
	private:
		std::string _message;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		~GradeTooLowException() throw () {}
        GradeTooLowException &setName(const std::string &n)
        {
            _message = "Grade too low for '" + n + "'";
            return (*this);
        }
		const char *what () const throw () {
			return (_message.c_str());
		}
	private:
		std::string _message;
	};


protected:
	std::string	_name;
	int			_grade;

private:
	void gradeValidator(int g);


};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value);

#endif
