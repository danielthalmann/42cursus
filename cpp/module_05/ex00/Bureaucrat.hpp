#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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


	class GradeException : public std::exception
	{
	public:
		~GradeException() throw () {}
        GradeException &setName(const std::string &n)
        {
            _name = n;
            return (*this);
        }
	private:
		std::string _name;
	};


	class GradeTooHighException : public GradeException
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

	class GradeTooLowException : public GradeException
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

#endif
