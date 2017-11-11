#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
using namespace sf;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Dead, Injured, Follow, Move };


struct Damage { int min, max; };
struct ObjectSize { int x, y, x1, y1, x2, y2; };
struct ObjSize { int x, y; };
struct HeroCharacteristic {
	int base_hp = 0;
	float base_cooldown = 0;
	int exp = 0;
	int exp_to_level = 0;
	int level = 0;
	int strength = 0;
	int stamina = 0;
	int agility = 0;
};


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
		else if (Cell == ' ')
		{
			obj.setTextureRect(IntRect(12 * 33, 17 * 33, 32, 32));
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
	static GameMap& getMap() { static GameMap INSTANCE; return INSTANCE; }
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
	static float reboundRange;
	float cooldown;
	float animationSpeed;
	float currentFrame;
	float moveSpeed;
	Damage damage;
	State state;
	Sprite character;
	Direction direction;
public:
	static float timeTick;
	virtual ~Character() =0 {}
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setState(State state) { this->state = state; }
	virtual void setMoveSpeed(float speed) { this->moveSpeed = speed; }
	virtual void setDirection(Direction dir) { this->direction = dir; }
	virtual float getCooldown() { return this->cooldown; }
	virtual float getAnimationSpeed() { return this->animationSpeed; }
	virtual float getCurrentFrame() { return this->currentFrame; }
	virtual float getMoveSpeed() { return this->moveSpeed; }
	virtual State getState() { return this->state; }
	virtual Sprite& getSprite() { return character; }
	virtual Direction getDirection() { return this->direction; }
	virtual Damage getDamage() { return this->damage; }
	void setCurrentFrame(int frame) { this->currentFrame = frame; }
	virtual void move(Direction dir)
	{
		direction = dir;
		if (dir == Direction::Up) character.move(0, timeTick / moveSpeed * -1);
		else if (dir == Direction::Down) character.move(0, timeTick / moveSpeed);
		else if (dir == Direction::Left) character.move(timeTick / moveSpeed * -1, 0);
		else if (dir == Direction::Right) character.move(timeTick / moveSpeed, 0);
	}

	bool checkCharacerCollision(const sf::FloatRect &obj)
	{
		sf::Rect<float> r1 = character.getGlobalBounds();
		sf::Rect<float> r2 = obj;
		return r1.intersects(r2);
	}
	bool checkWall—ollision()
	{
		IntRect size = character.getTextureRect();
		ObjectSize pos;
		pos.x = character.getPosition().x + 3;
		pos.y = character.getPosition().y + 3;

		if (pos.x / size.width < 0 || pos.x / 32 >= GameMap::width || pos.y / size.height < 0 || pos.y / 64 >= GameMap::height)
			return true;

		pos.x1 = pos.x + size.width * character.getScale().x - 6;
		pos.y1 = pos.y + size.height * character.getScale().y - 6;
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
float Character::timeTick = 0;
float Character::reboundRange = 0;

class Enemy : public Character
{
	static int count;
	int pos_change_chance;
public:
	Enemy(int chance = 500) : pos_change_chance(chance) { ++count; }
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
	void setPositionChange—hance(int value)
	{
		if (value >=0 && value < 1000)
		pos_change_chance = value;
	}
	int const &getCount() { return count; }
};

int Enemy::count = 0;

class Scorpion : public Enemy
{
	Scorpion() : Enemy::Enemy() {}
};

class Player : public Character
{
	string name;
	Damage base_dmg;
	RectangleShape sword;
	HeroCharacteristic stats;
	
	void StatsByLevelUp()
	{
		stats.strength += 2 + stats.level / 10 * 2;
		stats.stamina += 2 + stats.level / 10 * 2;
		stats.agility += 2 + stats.level / 10 * 2;
		stats.base_hp += stats.level * 10;
		stats.exp_to_level *= stats.level;
		stats.exp = 0;
	}
public:
	Player(string name, int hp, float cooldown = 0.005, int x = 0, int y = 0, int min = 0, int max = 0) : Character::Character()
	{
		character.setTexture(LoadTextures::Load().Hero);
		character.setTextureRect(IntRect(0, 0, 32, 64));
		animationSpeed = 0.005;
		sword.setSize(Vector2f(32, 32));
		this->name = name;
		this->state = State::Idle;
		this->stats.base_hp = hp;
		this->direction = Direction::Right;
		this->character.setPosition(x,y);
		this->base_dmg.min = min;
		this->base_dmg.max = max;
		this->stats.base_cooldown = cooldown;
		this->reboundRange = 0;
		AbilitiesAutoChange();
	}
	void setParams(int strenght, int endurance, int dexterity)
	{
		this->stats.strength = strenght;
		this->stats.stamina = endurance;
		this->stats.agility = dexterity;
	}
	void AbilitiesAutoChange()
	{
		hp = stats.base_hp + stats.stamina * 2;
		damage.min = base_dmg.min + stats.strength / 2;
		damage.max = base_dmg.max + stats.strength;
		cooldown = stats.base_cooldown - stats.agility / 100;
		if (cooldown < 0) cooldown = 0.05;
	}
	RectangleShape& getSword() { return sword; }
	void idleAnimation()
	{
		currentFrame = 1;
		if (direction == Down) character.setTextureRect(IntRect(0, 0, 32, 64));
		else if (direction == Up) character.setTextureRect(IntRect(0, 64, 32, 64));
		else if (direction == Right) character.setTextureRect(IntRect(0, 192, 32, 64));
		else if (direction == Left) character.setTextureRect(IntRect(0, 128, 32, 64));
	}
	void moveAnimation()
	{

		if (direction == Up)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 4;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 64, 32, 64));
		}
		else if (direction == Down)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 4;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 0, 32, 64));
		}

		else if (direction == Left)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 4;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 128, 32, 64));
		}
		else if (direction == Right)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 4;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 192, 32, 64));
		}
	}
	void attackAnimation()
	{
		currentFrame += animationSpeed *timeTick + cooldown;
		if (currentFrame > 5) { state = Idle; loadDefaultTexture(); return;}
		
		if (direction == Left)	
			character.setTextureRect(IntRect(int(currentFrame) * 64 + 64, 0, -64, 64));
		else
			character.setTextureRect(IntRect(int(currentFrame) * 64, 0, 64, 64));
	}
	void injureAnimation()
	{
		reboundRange += timeTick;
		if (direction == Up)
			character.move(0, -timeTick / 3);
		else if (direction == Down)
			character.move(0, timeTick / 3);
		else if (direction == Left)
			character.move(-timeTick / 3, 0);
		else if (direction == Right)
			character.move(timeTick / 3, 0);
		if (int(reboundRange) % 5 == 0)
			character.setColor(Color::Red);
		else if (int(reboundRange) % 2 == 0)
			character.setColor(Color::White);
		if (reboundRange > 600)
		{
			character.setColor(Color::White);
			reboundRange = 0;
			state = Idle;
		}
	}
	void loadAttackTexture()
	{
		character.setTexture(LoadTextures::Load().HeroAttack);
	}
	void loadDefaultTexture()
	{
		character.setTexture(LoadTextures::Load().Hero);
	}
};

class AssembledGame
{
	Player* hero;
	vector<Enemy*> enemies;
	static RenderWindow window;
	View view;
	GameMap& map;
	Clock clock;
	int height;
	int width;
	AssembledGame() : map(GameMap::getMap())
	{
		hero = nullptr;
		height = VideoMode::getDesktopMode().height;
		width = VideoMode::getDesktopMode().width;
		view.reset(sf::FloatRect(0, 0, width, height));
	}
public:
	void addHero(Player &player) { hero = new Player{ player }; }
	void addEnemy(Enemy enemy)
	{

		enemies.push_back(new Enemy{ enemy });
	}
	void updateTime()
	{
		Character::timeTick = clock.getElapsedTime().asMicroseconds();
		Character::timeTick /= 500;
		clock.restart();
	}
	static AssembledGame& getGame() { static AssembledGame gameStart; return gameStart; }

	void heroCamTracing()
	{
		float temp_x = hero->getSprite().getPosition().x;
		float temp_y = hero->getSprite().getPosition().y;
		if (temp_x < width / 2)
			temp_x = width / 2;
		if (temp_y < height / 2)
			temp_y = height / 2;
		if (temp_x > map.width * 32 - width / 2)
			temp_x = map.width * 32 - width / 2;
		if (temp_y > map.height * 32 - height / 2)
			temp_y = map.height * 32 - height / 2;

		view.setCenter(temp_x, temp_y);
		window.setView(view);
	}
	void game()
	{
		srand(time(0));

// ************************************************************* Events ******************************************************

		while (window.isOpen())
		{
			//Set Game Glock
			updateTime();
			
			//Events
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}


// ************************************************* Hero move control ***************************************************
			
			Vector2f hero_position_buffer = hero->getSprite().getPosition();
			if (hero->getState() == Idle || hero->getState() == Move)
			{
				
				hero->setState(Move);

				if (sf::Keyboard::isKeyPressed(Keyboard::W))
					hero->move(Up);
				else if (sf::Keyboard::isKeyPressed(Keyboard::S))
					hero->move(Down);
				else if (sf::Keyboard::isKeyPressed(Keyboard::A))
					hero->move(Left);
				else if (sf::Keyboard::isKeyPressed(Keyboard::D))
					hero->move(Right);
				else 
					hero->setState(Idle);


				if (sf::Keyboard::isKeyPressed(Keyboard::Space))
				{
					hero->setCurrentFrame(0);
					hero->setState(Attack);
					hero->loadAttackTexture();
				}

				if (sf::Keyboard::isKeyPressed(Keyboard::U)) hero->setState(Injured);
			}

// ******************************************************* Hero Action animation ************************************************************

			//Hero move animation
			if (hero->getState() == Move) hero->moveAnimation();

			//Hero Idle animation
			if (hero->getState() == Idle) hero->idleAnimation();

			//Hero Attack animation
			if (hero->getState() == Attack) hero->attackAnimation();

			//Hero Injured animation
			if (hero->getState() == Injured) hero->injureAnimation();

// ******************************************************* Check Collision ************************************************************
			//Check Wall Collision
			if (hero->checkWall—ollision()) hero->getSprite().setPosition(hero_position_buffer);

// ************************************ Set Hero Sword Position ***************************************************
		
			if (hero->getDirection() == Up)
				hero->getSword().setPosition(hero->getSprite().getPosition().x, hero->getSprite().getPosition().y - 16);
			else if (hero->getDirection() == Down)
				hero->getSword().setPosition(hero->getSprite().getPosition().x, hero->getSprite().getPosition().y + 48);
			else if (hero->getDirection() == Left)
				hero->getSword().setPosition(hero->getSprite().getPosition().x - 8, hero->getSprite().getPosition().y + 16);
			else if (hero->getDirection() == Right)
				hero->getSword().setPosition(hero->getSprite().getPosition().x + 40, hero->getSprite().getPosition().y + 16);
			
			

// ********************************************* Hero Camera Tracing ************************************************
			heroCamTracing();
//  ************************************** Drawing *******************************************************


			
			


			//Clear Window
			window.clear();

			//Draw Cells
			for (int i = 0; i < map.height; i++)
			{
				for (int j = 0; j < map.width; j++)
				{
					window.draw(StaticObjects::Load().getObj());
					StaticObjects::Load().getCellObj(map.map[i][j]).setPosition(j * 32, i * 32);
				}
			}
			//Draw Hero
			window.draw(hero->getSprite());
			//Display
			window.display();
//**********************************************************************************************************

		}	
	}
};

RenderWindow AssembledGame::window(VideoMode::getDesktopMode(), "Game", Style::Fullscreen);