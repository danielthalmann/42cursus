#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <iostream>

#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator {

private:

	std::map<std::string, ATarget*> _targets;

public:
	TargetGenerator() {}
	virtual ~TargetGenerator() {
		for(std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it)
			delete it->second;
	}
 
	void learnTargetType(ATarget *target)
	{
		try{
			_targets.at(target->getType());
		} catch (...)
		{
			_targets[target->getType()] = target->clone();
		}
	}

	void forgetTargetType(const std::string name)
	{
		try{
			ATarget *target = _targets.at(name);
			delete target;
			_targets.erase(name);
		} catch (...)
		{
		}
	}

	ATarget *createTarget(const std::string name)
	{
		try{
			return _targets.at(name);
		} catch (...)
		{
			return NULL;
		}

	}

};


#endif

