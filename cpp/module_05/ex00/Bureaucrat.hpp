#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{

public:

	static const int	min_grade = 1;
	static const int	max_grade = 150;

	Bureaucrat();
	Bureaucrat(std::string n, int g);
	virtual ~Bureaucrat();
	Bureaucrat(Bureaucrat &b);
	Bureaucrat &operator=(Bureaucrat &b);


    /**
     * @brief Exception lorsque le fichier n'arrive pas à s'ouvrir
     *
     */
    class GradeTooHighException : public std::exception
    {
    public:
        ~GradeTooHighException() throw () {}
        const char *what () const throw () {
            return ("GradeTooHigh");
        }
    };


protected:
	std::string	_name;
	int			_grade;


};

#endif
