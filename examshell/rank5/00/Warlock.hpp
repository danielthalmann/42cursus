#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
    
public:

    Warlock();
    virtual ~Warlock();
    Warlock(const Warlock& other);
    Warlock &operator=(const Warlock& other);

public:
    std::string &getTitle() const;
    std::string &getName() const;
    
private:

    std::string name;
    std::string title;

};

#endif