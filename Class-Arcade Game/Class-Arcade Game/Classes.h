#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#define COORDS(x, y) 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(x), short(y) });
using namespace std;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Defend, Shoot, Dead, Damaged, Follow };
enum MapCell { Empty, Wall, Hole };
const int field_width = 55;
const int field_height = 50;
class Character;
class Player;


void hideCursor(bool switch_cursor)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !switch_cursor;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}


struct Position { int x, y; };
struct Damage { int min, max; };
struct CursorStart { int x, y; };
struct ObjectSize { int x, y, x1, y1, x2, y2; };

class IMovable
{
protected:
	Direction direction;
public:
	virtual bool move(Direction dir) = 0 {};
};

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

class IInteractive
{
public:
	virtual void interaction(Character &target) = 0; //typeid Player
};

class GameObject
{
protected:
	Position position;
public:
	virtual ~GameObject() = 0 {}
	virtual void setPosition(int x, int y) { this->position.x = x; this->position.y = y; }
	virtual Position getPosition() { return this->position; }
};

class Coin : public GameObject, public IInteractive
{
	virtual void interaction(Character & target) override;
};

class Trap : public GameObject, public IInteractive
{
	virtual void interaction(Character & target) override;
};



class Map 
{
	vector<vector<MapCell>> field;
	Map()
	{
		field.resize(height);
		for (int i = 0; i < height; i++)
		{
			field[i].resize(width);
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int code = rand() % 55;
				if (i == 0 || i == height - 1)
					field[i][j] = MapCell::Wall;
				else if (j == 0 || j == width - 1 || code < 2)
					field[i][j] = MapCell::Wall;
				else 
					field[i][j] = MapCell::Empty;
			}
		}
	}
public:
	static const int width;
	static const int height;

	static Map& get()
	{
		static Map INSTANCE;
		return INSTANCE;
	}

	MapCell getCell(int x, int y)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
			return field[y][x];
		else
			return MapCell::Wall;
	}
};


const int Map::width = field_width;
const int Map::height = field_height;


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
	virtual bool move(Direction dir)
	{
		Position temp = position;
		if (dir == Direction::Up)  position.y--;
		else if (dir == Direction::Down) position.y++;
		else if (dir == Direction::Left) position.x--;
		else if (dir == Direction::Right) position.x++;

		MapCell cell = Map::get().getCell(position.x, position.y);

		if (cell = MapCell::Wall)
		{position = temp; return false;}
		else
			return true;
	}
};



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
class Enemy : public Character
{
	static int count;
	int pos_change_chance;
public:
	Enemy(int x, int y, int chance = 10) : pos_change_chance(chance) { position.x = x; position.y = y; count++; }
	virtual void scanMap(Player &plr)
	{
		int Px = plr.getPosition().x;
		int Py = plr.getPosition().y;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (position.x - j == Px && position.y - i == Py || position.x + j == Px && position.y - i == Py)
					0;
			}
		}
	}
	void ChangePos()
	{
		int random = rand() % pos_change_chance;
		if (random == 1)
			direction = Direction(rand() % 4);
		if (!move(direction))
			direction = Direction(rand() % 4);
	}
	int getCount() { return count; }
};

int Enemy::count = 0;

class Zombie : public Enemy
{
	static Damage damage;
	static int cooldown;
public:
	Zombie(int x, int y) : Enemy(x, y) {}
	
};

class Skeleton : public Enemy
{
	static Damage damage;
	static int cooldown;
public:
	Skeleton(int x, int y) : Enemy(x, y) {}
};

class Game
{
	Map& map;
	char ScreenBuffer[Map::height][Map::width];
	Player& player;
	CursorStart start;
	vector<GameObject> staticObjects;
	vector<Enemy*> enemies;
	void Draw()
	{
		for (int i = 0; i < map.height; i++)
		{
			for (int j = 0; j < map.width; j++)
			{
				COORDS(start.x + j, start.y + i);
				cout << ScreenBuffer[i][j];
			}
		}
		COORDS(0, start.y + map.height);
	}
public:
	Game(Player &p, int x, int y) : map(Map::get()), player(p) { start.x = x; start.y = y; }
	void  DrawMap()
	{
		for (int i = 0; i < map.height; i++)
		{
			for (int j = 0; j < map.width; j++)
			{
				if (map.getCell(j, i) == Wall)
					ScreenBuffer[i][j] = '#';
				else
					ScreenBuffer[i][j] = ' ';
			}
		}
		ScreenBuffer[player.getPosition().y][player.getPosition().x] = 'X';
		for (int i = 0; i < enemies.size(); i++)
		{
			ScreenBuffer[enemies[i]->getPosition().y][enemies[i]->getPosition().x] = 'W';
		}
		Draw();
	}
	void addEnemy(Enemy *en)
	{
		if (typeid(*en) == typeid(Zombie))
			enemies.push_back(new Zombie{ *dynamic_cast<Zombie*>(en) });
		else if (typeid(*en) == typeid(Skeleton))
			enemies.push_back(new Skeleton{ *dynamic_cast<Skeleton*>(en) });

	}
	int getEnemyCount() { return enemies.size(); }
	vector<Enemy*> &getEnemy() { return enemies; }
};