#pragma once
#include "Character.h"

class Player : public Character
{
	string name;
	Damage base_dmg;
	int base_hp;
	float base_cooldown;
	int exp;
	int exp_to_level;
	int level;
	int strength;
	int stamina;
	int agility;
	void StatsByLevelUp()
	{
		strength += 2 + level / 10 * 2;
		stamina += 2 + level / 10 * 2;
		agility += 2 + level / 10 * 2;
		base_hp += level * 10;
		exp_to_level *= level;
		exp = 0;
	}
public:
	Player(string name, int hp, float cooldown = 5, int min = 0, int max = 0, int x = 0, int y = 0) : exp(0), level(0), strength(0), stamina(0), agility(0), exp_to_level(500)
	{
		this->name = name;
		this->state = State::Idle;
		this->base_hp = hp;
		this->direction = Direction::Right;
		this->position.x = x;
		this->position.y = y;
		this->base_dmg.min = min;
		this->base_dmg.max = max;
		this->base_cooldown = cooldown;
		AbilitiesAutoChange();
	}
	void setParams(int strenght, int endurance, int dexterity)
	{
		this->strength = strenght;
		this->stamina = endurance;
		this->agility = dexterity;
	}
	void AbilitiesAutoChange()
	{
		hp = base_hp + stamina * 2;
		damage.min = base_dmg.min + strength / 2;
		damage.max = base_dmg.max + strength;
		cooldown = base_cooldown - agility / 100;
		if (cooldown < 0) cooldown = 0.05;
	}
};
