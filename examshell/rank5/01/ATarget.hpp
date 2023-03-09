#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ATarget {

private:    

public:

    ATarget(const std::string &t = "");
    virtual ~ATarget();
    ATarget(const ATarget& other);
    ATarget &operator=(const ATarget& other);

public:
    void getHitBySpell(const ASpell &spell);
    const std::string &getType() const;
    ASpell *clone() const = 0;
    
private:

    std::string _type;

};

#endif