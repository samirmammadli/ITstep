#pragma once
#include "Trap.h"


class Character : public GameObject, public IAttacking, public IMovable
{
	int hp;
	State state;

public:
	virtual void attack(Character &target) override;
	virtual void shoot(Character &target) override;
	virtual void move(Direction dir) override;
};

