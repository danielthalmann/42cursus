#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
    Brain();
    Brain(Brain &brain);
    virtual ~Brain();
    Brain &operator=(const Brain &brain);

private:
    std::string _ideas[100];

};

#endif