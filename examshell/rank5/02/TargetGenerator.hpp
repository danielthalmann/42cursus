#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <string>

class TargetGenerator {

private:



public:
    TargetGenerator() {}
    ~TargetGenerator() 
    {
        free();
    }

    void learnTargetType(ATarget* target)
    {
        try {
            _targets.at(target->getType());
        } catch (...)
        {
            _targets[target->getType()] = target->clone();
        }
    }
    
    void forgetTargetType(std::string const &targetname)
    {
        _targets.erase(targetname);
    }

    ATarget* createTarget(std::string const &targetname)
    {
        return _targets.at(targetname);
    }

    void free()
    {
        for(std::map<std::string, ATarget*>::const_iterator i = _targets.begin(); i != _targets.end(); i++)
            delete i->second;

        _targets.clear();
    }


private:
    std::map<std::string, ATarget*> _targets;

};


#endif
