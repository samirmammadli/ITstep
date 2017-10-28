
#include "IMovable.h"
class IAttacking
{
protected:
	Damage damage;
	float cooldown;
public:
	virtual ~IAttacking() = 0 {}
	virtual void attack(Character &target) {};
	virtual void shoot(Character &target) {};
	virtual void setCooldown(int time) { this->cooldown = time; }
};
