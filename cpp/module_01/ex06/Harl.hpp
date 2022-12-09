
#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl;
typedef struct s_loglevel
{
    std::string name;
    void (Harl::*fn)( void );

} t_loglevel;

class Harl
{
public:
    Harl();
    ~Harl();

    void complain( std::string level );

private:

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    t_loglevel _levels[4];

};

#endif