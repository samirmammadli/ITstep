#pragma once
#include "Structures.h"
class IMovable
{
protected:
	Direction direction;
public:
	virtual void move(Direction dir) { this->direction = dir; };
	virtual ~IMovable() = 0 {}
};
