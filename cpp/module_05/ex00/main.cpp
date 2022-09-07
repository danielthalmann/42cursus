
#include <iostream>
#include "Bureaucrat.hpp"

int main ( )
{
	
	try{

		Bureaucrat b;

	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}



	return (0);
}

    /**
     * @brief Exception lorsque le fichier n'arrive pas à s'ouvrir
     *
     */
	/*
    class OpenFileException : public std::exception
    {
    public:
        ~OpenFileException() throw ()
        {}
        OpenFileException &setFileName(const std::string &filename)
        {
            _message = "Impossible d'ouvrir le fichier '" + filename + "'";
            return (*this);
        }
        const char *what () const throw () {
            return (_message.c_str());
        }
    private:
        std::string _message;
    };


throw OpenFileException().setFileName(filename);


try{

}
catch(SearchReplace::OpenFileException &e)
{
	e.what();
}

*/
