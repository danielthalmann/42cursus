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

    std::string *getIdeas();
    static const int sizeOfIdeas = 100;

private:
    std::string _ideas[Brain::sizeOfIdeas];

};

#endif