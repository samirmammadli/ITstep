#pragma once
#include "IMovable.h"
class IAttacking
{
	Damage damage;
	int cooldown;
public:
	virtual void attack(Character &target) = 0;
	virtual void shoot(Character &target) = 0;
};
