#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <string>
#include <iostream>

#include "ATarget.hpp"


class BrickWall : public ATarget {

public:
	BrickWall()
	 : ATarget("Inconspicuous Red-brick Wall")  { }
	virtual ~BrickWall() {}
	BrickWall(const BrickWall &other)
 	 : ATarget(other) {	}
	BrickWall &operator=(const BrickWall &other)
	{ 
		ATarget::operator=(other);
		return *this;
	}
	virtual ATarget *clone(){ return new BrickWall(*this); }
};


#endif

