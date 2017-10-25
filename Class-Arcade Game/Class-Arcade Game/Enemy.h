#pragma once
#include "Player.h"

class Enemy : public Character
{
	static int count;
public:
	virtual void scanMap() = 0;
};

