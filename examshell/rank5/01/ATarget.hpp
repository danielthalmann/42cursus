#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ATarget {

private:    

public:

    ATarget(const std::string &t = "");
    virtual ~ATarget();
    ATarget(const ATarget& other);
    ATarget &operator=(const ATarget& other);

public:
    const std::string &getType() const;
    ASpell *clone() = 0;
    
private:

    std::string type;

};

#endif