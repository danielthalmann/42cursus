
#include "Warlock.hpp"

Warlock::Warlock()
: name("noname"), title("notitle")
{

}

Warlock::Warlock(std::string &n, std::string &t)
: name(n), title(t)
{

}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getTitle() const
{
    return title;
}

const std::string &Warlock::getName() const
{
    return name;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}