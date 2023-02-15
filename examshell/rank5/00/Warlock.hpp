#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {

private:    
    Warlock();

public:

    Warlock(std::string &n, std::string &t);
    virtual ~Warlock();
//    Warlock(const Warlock& other);
//    Warlock &operator=(const Warlock& other);

public:
    const std::string &getTitle() const;
    const std::string &getName() const;
    void introduce() const;
    
private:

    std::string name;
    std::string title;

};

#endif