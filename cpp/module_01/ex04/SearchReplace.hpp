#ifndef SEARCHREPLACE_H
#define SEARCHREPLACE_H
#include <iostream>
#include <fstream>
#include "colors.hpp"


class SearchReplace
{
public:

    SearchReplace();
    ~SearchReplace();

    void setSearch(const std::string &search);
    void setReplace(const std::string &replace);
    void setFileName(const std::string &filename);
    void replace( void );

    /**
     * @brief Exception lorsque le fichier n'arrive pas à s'ouvrir
     * 
     */
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


private:

    std::string _search;
    std::string _replace;
   	std::ifstream _file_in; 
    std::ofstream _file_out;

    OpenFileException _openFileException;

};

#endif