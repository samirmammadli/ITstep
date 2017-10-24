#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace sf;
using namespace std;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall, Hole };
struct Position { int x, y; };
struct Damage { int min, max; };

class Character;

class IMovable
{
	Direction direction;
public:
	virtual void move(Direction dir) = 0;
};

class IAttacking
{
	Damage damage;
	int cooldown;
public:
	virtual void attack(Character &target) = 0;
	virtual void shoot(Character &target) = 0;
};

class IInteractive
{
public:
	virtual void interaction(Character &target) = 0; //typeid Player
};

class GameObject
{
	Position position;
};

class Coin : public GameObject, public IInteractive
{
	virtual void interaction(Character & target) override;
};

class Trap : public GameObject, public IInteractive
{
	virtual void interaction(Character & target) override;
};

class Character : public GameObject, public IAttacking, public IMovable
{
	int hp;
	State state;

public:
	virtual void attack(Character &target) override;
	virtual void shoot(Character &target) override;
	virtual void move(Direction dir) override;
};

class Player : public Character
{
	std::string name;
	int exp;
	int level;
	int strength;
	int endurance;
	int dexterity;
};

class Enemy : public Character
{
	static int count;
public:
	virtual void scanMap() = 0;
};

class Zombie : public Enemy
{

};

class Skeleton : public Enemy
{

};

class Map
{
	MapCell field[50][50];
public:
	MapCell getCell(int x, int y);
};

/*
Files
const, final, override
smart pointers
*/


class Game
{
	Map& map;
	Player& player;
	vector<GameObject> staticObjects;
	vector<Enemy> enemies;
};

//void main()
//{
//	//Game initialization
//
//	//Game loop
//	while (true)
//	{
//		//Input handling
//
//		//Game logic
//
//		//Drawing
//	}
//}


bool CheckPosition(string *map, Sprite sprit)
{
	int x;
	int y;
	for (int i = 0; i < 25; i++)
	{
		x = sprit.getPosition().x;
		y = sprit.getPosition().y;
		for (int j = 0; j < 20; j++)
		{
			
			if (map[j][i] == '0')
			{
				if (x >= i * 31 && x <= i * 31 + 31 && y >= j * 31 && y <= j * 31 + 31)
					return true;
			}	
		}
	}
	return false;
}


int main()
{
	string map[20] = {
		"000000000000000000000000",
		"000000000000000000000000",
		"000000000000000000000000",
		"000000000000000000000000",
		"000000000000000000000000",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"0                      0",
		"000000000000000000000000"
	};

	ContextSettings settings;
	Clock clock;
	Texture texture;
	Texture floor_t;
	Image image;
	Image floor;
	floor.loadFromFile("images\\5.png");
	image.loadFromFile("F:\\chel.png");
	//image.createMaskFromColor(Color(0, 255, 0));
	floor_t.loadFromImage(floor);
	texture.loadFromImage(image);
	Sprite new_sprite;
	Sprite floor_s;
	floor_s.setTexture(floor_t);
	floor_s.setTextureRect(IntRect(4,3, 31,31));
	floor_s.setPosition(0, 0);
	new_sprite.setTexture(texture);
	new_sprite.setTextureRect(IntRect(0, 195, 65, 65));
	new_sprite.setPosition(20, 20);


	RenderWindow window(VideoMode(800, 620), "SFML works!");

	float x = 0, y = 0;
	double CurrentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 3000;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


			if (sf::Keyboard::isKeyPressed(Keyboard::W))
			{
				new_sprite.move(0, -time);
				if (sf::Keyboard::isKeyPressed(Keyboard::W)) CurrentFrame += 0.058*time;
				if (CurrentFrame > 9) CurrentFrame = 1; // если пришли к третьему кадру - откидываемся назад.
				new_sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 0, 64, 64));
				
			}
				
			else if (sf::Keyboard::isKeyPressed(Keyboard::S))
			{
				new_sprite.move(0, time);
				CurrentFrame += 0.058*time;
				if (CurrentFrame > 9) CurrentFrame = 1; // если пришли к третьему кадру - откидываемся назад.
				new_sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 130, 64, 64));
		
			}
				
			else if (sf::Keyboard::isKeyPressed(Keyboard::A))
			{
				new_sprite.move(-time, 0);
				CurrentFrame += 0.058*time;
				if (CurrentFrame > 9) CurrentFrame = 1; // если пришли к третьему кадру - откидываемся назад.
				new_sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 64, 64, 64));
				
			}
				
			else if (sf::Keyboard::isKeyPressed(Keyboard::D))
			{
				if (!CheckPosition(map, new_sprite));
				{
					new_sprite.move(time, 0);
					CurrentFrame += 0.058*time;
					if (CurrentFrame > 9) CurrentFrame = 1; // если пришли к третьему кадру - откидываемся назад.
					new_sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 192, 64, 64));
				}	
			}


		window.clear();
		
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (map[i][j] == '0')
					floor_s.setPosition(j*31, i*31);
				window.draw(floor_s);
			}
		}
		window.draw(new_sprite);
		window.display();
	}

	return 0;
}