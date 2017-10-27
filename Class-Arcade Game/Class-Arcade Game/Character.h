#pragma once
#include "Trap.h"


class Character : public GameObject, public IAttacking, public IMovable
{
protected:
	int hp;
	State state;
public:
	virtual ~Character() = 0 {}
	virtual void attack(Character &target) override {};
	virtual void shoot(Character &target) override {};
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setState(State state) { this->state = state; }
};

