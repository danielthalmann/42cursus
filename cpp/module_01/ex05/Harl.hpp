/* ************************************************************************** */
/*                                                                         
/*                                                      .   :::::::: 
/*   Harl.hpp                                          :    :+:    :+: 
/*                                                    +  +       +:+     
/*   By: dthalman <daniel@thalmann.li>               +-+-+-       +#+     
/*                                                    +-           */
/*   Created: 2022/05/14 11:29:03 by dthalman         
             */
/*   Updated: 2022/05/14 11:29:03 by dthalman        ######.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_H
#define HARL_H
#include <iostream>

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

private:

    void (fn*[5])( void ) 

};

#endif