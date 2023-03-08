#include "ATarget.hpp"

ATarget::ATarget(const std::string &t = "")
{

}

ATarget::~ATarget()
{

}

ATarget::ATarget(const ATarget& other)
{
    *this = other;
}

ATarget::ATarget &operator=(const ATarget& other)
{

}


const std::string &getType() const
{
    return type;
}
