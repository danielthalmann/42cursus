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
    virtual ATarget *clone() = 0;

public:
    const std::string &getType() const;
    
private:

    std::string type;

};

#endif