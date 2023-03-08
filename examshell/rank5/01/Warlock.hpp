#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {

private:    
    Warlock();

public:

    Warlock(const std::string &n, const std::string &t);
    virtual ~Warlock();
//    Warlock(const Warlock& other);
//    Warlock &operator=(const Warlock& other);

public:
    const std::string &getTitle() const;
    const std::string &getName() const;
    void setTitle(const std::string &t);
    void introduce() const;
    
private:

    std::string name;
    std::string title;

};

#endif