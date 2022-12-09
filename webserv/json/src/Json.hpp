#ifndef DOG_HPP
#define DOG_HPP

#include "Json.hpp"
#include <iostream>
#include <map>

class Json
{
public:
    Json();
    Json(Json &json);
    virtual ~Json();
    Json &operator=(const Json &json);



private:

    
};

#endif