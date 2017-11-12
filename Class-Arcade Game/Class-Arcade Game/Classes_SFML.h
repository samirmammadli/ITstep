#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
using namespace sf;

enum Direction { Up, Down, Left, Right };
enum Action { Idle, Attack, Follow, Move };
enum State { Dead, Injured, Normal };


struct Damage { int min = 0, max = 0; };
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
	Direction reboundDir;
	float cooldown;
	float animationSpeed;
	float currentFrame;
	float moveSpeed;
	Damage damage;
	Action action;
	State state;
	Sprite character;
	Direction direction;
public:
	static float timeTick;
	virtual ~Character() =0 {}
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setReboundDir(Direction dir) { this->reboundDir = dir; }
	virtual void setState(State state) { this->state = state; }
	virtual void setAction(Action action) { this->action = action; }
	virtual void setMoveSpeed(float speed) { this->moveSpeed = speed; }
	virtual void setDirection(Direction dir) { this->direction = dir; }
	virtual float getCooldown() { return this->cooldown; }
	virtual float getAnimationSpeed() { return this->animationSpeed; }
	virtual float getCurrentFrame() { return this->currentFrame; }
	virtual float getMoveSpeed() { return this->moveSpeed; }
	virtual bool CheckCollision(const sf::FloatRect &obj)
	{
		return character.getGlobalBounds().intersects(obj);
	}
	virtual Action getAction() { return this->action; }
	virtual State getState() { return this->state; }
	virtual Sprite& getSprite() { return character; }
	virtual Direction getDirection() { return this->direction; }
	virtual Damage getDamage() { return this->damage; }
	void setCurrentFrame(int frame) { this->currentFrame = frame; }
	virtual void move()
	{
		if (direction == Direction::Up) character.move(0, timeTick / moveSpeed * -1);
		else if (direction == Direction::Down) character.move(0, timeTick / moveSpeed);
		else if (direction == Direction::Left) character.move(timeTick / moveSpeed * -1, 0);
		else if (direction == Direction::Right) character.move(timeTick / moveSpeed, 0);
	}

	bool checkCharacerCollision(const sf::FloatRect &obj)
	{
		sf::Rect<float> r1 = character.getGlobalBounds();
		sf::Rect<float> r2 = obj;
		return r1.intersects(r2);
	}
	bool checkWall�ollision(bool firstDrawing = false)
	{
		IntRect size = character.getTextureRect();
		ObjectSize pos;
		pos.x = character.getPosition().x;
		pos.y = character.getPosition().y;

		if (pos.x / size.width < 0 || pos.x / 32 >= GameMap::width || pos.y / size.height < 0 || pos.y / 64 >= GameMap::height)
			return true;

		pos.x1 = pos.x + size.width * character.getScale().x;
		pos.y1 = pos.y + size.height * character.getScale().y;

		if (!firstDrawing)
		{
			pos.x += 3;
			pos.y += 3;
			pos.x1 -= 6;
			pos.y1 -= 6;
		}

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

	virtual void injureReaction()
	{
		reboundRange += timeTick;
		if (reboundDir == Up)
			character.move(0, -timeTick / 3);
		else if (reboundDir == Down)
			character.move(0, timeTick / 3);
		else if (reboundDir == Left)
			character.move(-timeTick / 3, 0);
		else if (reboundDir == Right)
			character.move(timeTick / 3, 0);
		if (int(reboundRange) % 5 == 0)
			character.setColor(Color::Red);
		else if (int(reboundRange) % 2 == 0)
			character.setColor(Color::White);
		if (reboundRange > 600)
		{
			character.setColor(Color::White);
			reboundRange = 0;
			state = Normal;
		}
	}
	
};
float Character::timeTick = 0;
float Character::reboundRange = 0;

class Enemy : public Character
{
protected:
	static int count;
	int pos_change_chance;
public:
	virtual ~Enemy() = 0 {}
	Enemy(int chance = 1000) : pos_change_chance(chance) { ++count; }
	void setRandDir()
	{
		direction = Direction(rand() % 4);
	}
	void updateDirection()
	{
		int random = rand() % pos_change_chance;
		if (random == 1)
			setRandDir();
	}
	void setDirectionChange�hance(int value)
	{
		if (value >=0 && value < 1000)
		pos_change_chance = value;
	}
	void setRandomPosition()
	{
		do
		{
			character.setPosition(rand() % GameMap::width  * 32, rand() % GameMap::height  * 32);
		} while (checkWall�ollision(true));
	}
	int const &getCount() { return count; }
};

int Enemy::count = 0;

class Scorpion : public Enemy
{
public:
	Scorpion() : Enemy::Enemy()
	{
		character.setTexture(LoadTextures::Load().Scorp);
		character.setTextureRect(IntRect(0, 32, 32, 32));
		moveSpeed = 12;
		animationSpeed = 0.005;
	}
	void moveAnimation()
	{
		if (direction == Up)
		{
			currentFrame += animationSpeed*timeTick;;
			if (currentFrame > 6) currentFrame -= 6;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 96, 32, 32));
		}
		else if (direction == Down)
		{
			currentFrame += animationSpeed*timeTick;;
			if (currentFrame > 6) currentFrame -= 6;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 30, 32, 32));
		}
		else if (direction == Left)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 6;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 160, 32, 32));

		}
		if (direction == Right)
		{
			currentFrame += animationSpeed*timeTick;
			if (currentFrame > 6) currentFrame -= 6;
			character.setTextureRect(IntRect(int(currentFrame) * 32, 224, 32, 32));
		}
	}
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
		this->action = Action::Idle;
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
		if (currentFrame > 5) { action = Idle; loadDefaultTexture(); return;}
		
		if (direction == Left)	
			character.setTextureRect(IntRect(int(currentFrame) * 64 + 64, 0, -64, 64));
		else
			character.setTextureRect(IntRect(int(currentFrame) * 64, 0, 64, 64));
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
	void addScorpion()
	{
		enemies.push_back(new Scorpion);

		enemies.back()->setRandomPosition();
		enemies.back()->getSprite().setScale(1.5, 1.5);
		enemies.back()->setDirection(Right);
		enemies.back()->setAction(Move);
		enemies.back()->setMoveSpeed(12);
		enemies.back()->setState(Normal);
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
			if (hero->getAction() == Idle || hero->getAction() == Move)
			{
				
				hero->setAction(Move);

				if (sf::Keyboard::isKeyPressed(Keyboard::W))
					hero->setDirection(Up);
				else if (sf::Keyboard::isKeyPressed(Keyboard::S))
					hero->setDirection(Down);
				else if (sf::Keyboard::isKeyPressed(Keyboard::A))
					hero->setDirection(Left);
				else if (sf::Keyboard::isKeyPressed(Keyboard::D))
					hero->setDirection(Right);
				else 
					hero->setAction(Idle);

				hero->getAction() == Move ? hero->move() : 0;

				if (sf::Keyboard::isKeyPressed(Keyboard::Space))
				{
					hero->setCurrentFrame(0);
					hero->setAction(Attack);
					hero->loadAttackTexture();
				}
			}



// ************************************************************ Enemy  ****************************************************************

			
			vector<Vector2f> enemy_pos_buffer;
			
			for (int i = 0; i < enemies.size(); i++)
			{
				enemy_pos_buffer.push_back(enemies[i]->getSprite().getPosition());

				//Enemies move
				if (enemies[i]->getAction() == Move)
				{
					enemies[i]->updateDirection();
					enemies[i]->move();
				}
				
				//Enemies move animation
				dynamic_cast<Scorpion*>(enemies[i])->moveAnimation();

				//Enemies and Hero collision check
				if (enemies[i]->checkCharacerCollision(hero->getSprite().getGlobalBounds()))
				{
					hero->setState(Injured);
					hero->setReboundDir(enemies[i]->getDirection());
				}
				//Enemies and Sword collision Check
				if (hero->getAction() == Attack)
				{
					if (enemies[i]->checkCharacerCollision(hero->getSword().getGlobalBounds()))
					{
						enemies[i]->setState(Injured);
						enemies[i]->setReboundDir(hero->getDirection());
					}
				}
				//Enemie Injured act
				if (enemies[i]->getState() == Injured) enemies[i]->injureReaction();


				//Enemies Wall Collision check
				if (enemies[i]->checkWall�ollision())
				{
					enemies[i]->getSprite().setPosition(enemy_pos_buffer[i]);
					enemies[i]->setRandDir();
				}
			}


			

// ******************************************************* Character Action animation ************************************************************

			//Hero move animation
			if (hero->getAction() == Move) hero->moveAnimation();

			//Hero Idle animation
			if (hero->getAction() == Idle) hero->idleAnimation();

			//Hero Attack animation
			if (hero->getAction() == Attack) hero->attackAnimation();


// ******************************************************* Character State reaction ************************************************************
			//Hero Injured act
			if (hero->getState() == Injured) hero->injureReaction();



// ************************************ Set Hero Sword Position ***************************************************
		
			if (hero->getDirection() == Up)
				hero->getSword().setPosition(hero->getSprite().getPosition().x, hero->getSprite().getPosition().y - 16);
			else if (hero->getDirection() == Down)
				hero->getSword().setPosition(hero->getSprite().getPosition().x, hero->getSprite().getPosition().y + 48);
			else if (hero->getDirection() == Left)
				hero->getSword().setPosition(hero->getSprite().getPosition().x - 8, hero->getSprite().getPosition().y + 16);
			else if (hero->getDirection() == Right)
				hero->getSword().setPosition(hero->getSprite().getPosition().x + 40, hero->getSprite().getPosition().y + 16);
			
// ************************************  Check Hero Wall Collision ******************************************************
			if (hero->checkWall�ollision()) hero->getSprite().setPosition(hero_position_buffer);

// ********************************************* Hero Camera Tracing ************************************************
			heroCamTracing();
//  ************************************** Drawing ******************************************************************


			
			


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

			//Draw Enemies
			for (int i = 0; i < enemies.size(); i++)
			{
				window.draw(enemies[i]->getSprite());
			}
			//Display
			window.display();
//**********************************************************************************************************

		}	
	}
};

RenderWindow AssembledGame::window(VideoMode::getDesktopMode(), "Game", Style::Fullscreen);