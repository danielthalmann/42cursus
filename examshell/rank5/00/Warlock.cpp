
#include "Warlock.hpp"

Warlock::Warlock()
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string &Warlock::getTitle() const
{
    return title;
}

std::string &Warlock::getName() const
{
    return name;
}
