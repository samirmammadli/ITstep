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
struct ObjSize { int x, y; };


class LoadTextures
{
	LoadTextures()
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
	static LoadTextures& Load()
	{
		static LoadTextures Textures;
		return Textures;
	}
};

class StaticObjects
{
	Sprite obj;
	StaticObjects() { obj.setTexture(LoadTextures::Load().Environment); }
public:
	static StaticObjects& Load()
	{
		static StaticObjects Obj;
		return Obj;
	}
	Sprite& getCellObj(char Cell)
	{
		obj.setColor(Color::White);
		if (Cell == '1')
		{
			obj.setTextureRect(IntRect(0, 33, 32, 32));
			return obj;
		}
		else if (Cell == '=')
		{
			obj.setTextureRect(IntRect(8 * 33, 33, 32, 32));
			return obj;
		}
		else if (Cell == '2')
		{
			obj.setTextureRect(IntRect(7 * 33, 33, 32, 32));
			return obj;
		}
		else if (Cell == '3')
		{
			obj.setTextureRect(IntRect(4 * 33, 33, 32, 32));
			return obj;
		}
		else if (Cell == '4')
		{
			obj.setTextureRect(IntRect(11 * 33, 33, 32, 32));
			return obj;
		}
		else if (Cell == '|')
		{
			obj.setTextureRect(IntRect(2 * 33, 33, 32, 32));
			return obj;
		}
		else
		{
			obj.setColor(Color::Transparent);
			return obj;
		}
	}
	const Sprite& getObj()
	{
		return obj;
	}
};

class GameMap {
public:
	static string* map;
	static const int width;
	static const int height;
	static char getCell(int x, int y)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
			return map[y][x];
		else
			return '=';
	}
};

const int GameMap::width = 55;
const int GameMap::height = 50;
string* GameMap::map = new string[GameMap::height]{
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
	"|        == == == == == == ==                         |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|                                                     |",
	"|        == == == == == == ==                         |",
	"|                                                     |",
	"|               |                                     |",
	"|               |                                     |",
	"|               |                                     |",
	"|               |                                     |",
	"|               3===2                                 |",
	"|                   |                                 |",
	"|                   |                                 |",
	"|                   |                                 |",
	"|          1========4                                 |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
	"|          |                                          |",
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
	Sprite character;
	Direction direction;
public:
	virtual ~Character() =0 {}
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setState(State state) { this->state = state; }
	virtual void move(Direction dir, float dist)
	{
		if (dir == Direction::Up) character.move(0,dist * -1);
		else if (dir == Direction::Down) character.move(0, dist);
		else if (dir == Direction::Left) character.move(dist * -1, 0);
		else if (dir == Direction::Right) character.move(dist, 0);
	}
	bool CheckCollision(const sf::FloatRect &obj)
	{
		sf::Rect<float> r1 = character.getGlobalBounds();
		sf::Rect<float> r2 = obj;
		return r1.intersects(r2);
	}
	bool checkWall()
	{
		IntRect size = character.getTextureRect();
		ObjectSize pos;
		pos.x = character.getPosition().x;
		pos.y = character.getPosition().y;

		if (pos.x / size.width < 0 || pos.x / 32 >= GameMap::width || pos.y / size.height < 0 || pos.y / 64 >= GameMap::height)
			return true;

		pos.x1 = pos.x + size.width * character.getScale().x;
		pos.y1 = pos.y + size.height * character.getScale().y;
		pos.y2 = pos.y + size.height / 2 * character.getScale().y;
		pos.x1 /= 32;
		pos.y1 /= 32;
		pos.x /= 32;
		pos.y /= 32;
		pos.y2 /= 32;


		if (GameMap::map[pos.y][pos.x] != ' ')
			return true;
		if (GameMap::map[pos.y][pos.x1] != ' ')
			return true;
		if (GameMap::map[pos.y1][pos.x] != ' ')
			return true;
		if (GameMap::map[pos.y1][pos.x1] != ' ')
			return true;
		if (GameMap::map[pos.y2][pos.x] != ' ')
			return true;
		if (GameMap::map[pos.y2][pos.x1] != ' ')
			return true;

		return false;
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
		character.setTexture(LoadTextures::Load().Hero);
		this->name = name;
		this->state = State::Idle;
		this->base_hp = hp;
		this->direction = Direction::Right;
		this->character.setPosition(x,y);
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