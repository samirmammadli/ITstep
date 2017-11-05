#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
using namespace sf;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Dead, Damaged, Follow };


struct Damage { int min, max; };
struct ObjectSize { int x, y, x1, y1, x2, y2; };


class LoadResources
{
	LoadResources()
	{
		Grass.loadFromFile("images\\grass.jpg");
		Environment.loadFromFile("images\\map.png");
		Scorp.loadFromFile("images\\scorpion.png");
		HeroAttack.loadFromFile("images\\hero_attack.png");
		Hero.loadFromFile("images\\hero_action.png");
	}
public:
	Texture Grass;
	Texture Hero;
	Texture Scorp;
	Texture HeroAttack;
	Texture Environment;
	static LoadResources& Load()
	{
		static LoadResources Textures;
		return Textures;
	}
};

class GameMap {

	static string map[];
	
public:
	static const int width;
	static const int height;
};

const int GameMap::width = 55;
const int GameMap::height = 50;
string GameMap::map[GameMap::height] = {
	"1=====================================================2",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|      ========2                                      |",
	"|              |                                      |",
	"|              |                                      |",
	"|              |           1===                       |",
	"|              |           |                          |",
	"|              |           |                          |",
	"|              |           |                          |",
	"|              3===========4                          |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"3=====================================================4"
};

class Character
{
protected:
	int hp;
	float cooldown;
	Damage damage;
	State state;
	Sprite Obj;
	Direction direction;
public:
	virtual ~Character() =0 {}
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setState(State state) { this->state = state; }
	virtual void move(Direction dir, float dist)
	{
		if (dir == Direction::Up) Obj.move(0,dist * -1);
		else if (dir == Direction::Down) Obj.move(0, dist);
		else if (dir == Direction::Left) Obj.move(dist * -1, 0);
		else if (dir == Direction::Right) Obj.move(dist, 0);
	}
};


class Enemy : public Character
{
	static int count;
	int pos_change_chance;
public:
	Enemy(int chance = 500) : pos_change_chance(chance) { count++; }
	void setRandPos()
	{
		direction = Direction(rand() % 4);
	}
	void updatePosition()
	{
		int random = rand() % pos_change_chance;
		if (random == 1)
			setRandPos();
	}
	int const &getCount() { return count; }
};

int Enemy::count = 0;



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
	Player(string name, int hp, float cooldown = 5, int x = 0, int y = 0, int min = 0, int max = 0) : exp(0), level(0), strength(0), stamina(0), agility(0), exp_to_level(500)
	{
		Obj.setTexture(LoadResources::Load().Hero);
		this->name = name;
		this->state = State::Idle;
		this->base_hp = hp;
		this->direction = Direction::Right;
		this->Obj.setPosition(x,y);
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