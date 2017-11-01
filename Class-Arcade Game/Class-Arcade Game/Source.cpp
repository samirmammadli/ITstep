//#include "Classes.h"
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;
using namespace sf;



/*
Files
const, final, override
smart pointers
*/

//void main()
//{
//	double start_time = 0;
//	double timer;
//
//	hideCursor(true);
//	srand(time(0));
//	Player pet("Samir", 200, 5, 10, 10);
//	Zombie zombak(10, 10);
//	Zombie zombak1(15, 10);
//	Zombie zombak2(11, 10);
//	Zombie zombak3(11, 10);
//	Game game(pet, 15, 5);
//	game.addEnemy(&zombak);
//	zombak.setPosition(11, 8);
//	game.addEnemy(&zombak1);
//	zombak.setPosition(22, 9);
//	game.addEnemy(&zombak2);
//	zombak.setPosition(0, 8);
//	game.addEnemy(&zombak3);
//	zombak.setPosition(18, 4);
//	game.addEnemy(&zombak);
//	zombak.setPosition(10, 10);
//	game.DrawMap();
//	Direction temp = Direction(rand() % 4);
//	zombak.move(Up);
//	bool MoveTime = false;
//
//	cout << zombak.getCount() << endl;
//	while (true)
//	{
//		timer = clock() / 100 - start_time;
//		COORDS(0, 0);
//		if (timer > 0.5) { start_time = clock() / 100; MoveTime = true; }
//
//		for (int i = 0; i < game.getEnemyCount(); i++)
//		{
//			
//			if (MoveTime) game.getEnemy()[i]->ChangePos();
//			
//		}
//		MoveTime = false;
//		if (_kbhit())
//		{
//			int key = _getch();
//			if (key == 'w')
//				pet.move(Direction::Up);
//			else if (key == 's')
//				pet.move(Direction::Down);
//			else if (key == 'a')
//				pet.move(Direction::Left);
//			else if (key == 'd')
//				pet.move(Direction::Right);
//			
//		}
//		game.DrawMap();
//		
//	}
//	
//}


bool checkPosition(string *map, int x, int y)
{
	if (x / 32 < 0 || x / 32>= 25 || y / 64 < 0 || y  / 64 >= 20)
		return true;
	//cout << x / 32  << "    " << y / 64 << endl;
	int x1 = x + 32 + 1;
	int y1 = y + 64 + 1;
	int y2 = y + 32 + 1;
	x1 /= 32;
	y1 /= 32;
	x /= 32;
	y /= 32;
	y2 /= 32;

	
	if (map[y][x] != ' ')
		return true;
	if (map[y][x1] != ' ')
		return true;
	if (map[y1][x] != ' ')
		return true;
	if (map[y1][x1] != ' ')
		return true;
	if (map[y2][x] != ' ')
		return true;
	if (map[y2][x1] != ' ')
		return true;

	return false;
}

void main()
{
	double speed = 0;
	string map[20] = {
		"1======================2",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"|                      |",
		"3======================4"
	};


	double check_x;
	double check_y;
	Texture Grass;
	Grass.loadFromFile("images\\grass.jpg");
	Clock clock;
	Texture texture;
	RectangleShape rect;
	rect.setTexture(&Grass);
	rect.setSize(Vector2f(24 * 32, 20 * 32));
	//Texture floor_t;
	Image image;
	Image image2;
	Texture Brick;
	Brick.loadFromFile("images\\map.png");
	Sprite brick;
	brick.setTexture(Brick);
	brick.setTextureRect(IntRect(528, 0, 32, 32));
	//528
	image2.loadFromFile("images\\hero_attack.png");
	//Image floor;
	//floor.loadFromFile("images\\5.png");
	image.loadFromFile("images\\hero_action.png");
	//image.createMaskFromColor(Color(0, 255, 0));
	//floor_t.loadFromImage(floor);
	texture.loadFromImage(image);
	Sprite new_sprite;
	//Sprite floor_s;
	//floor_s.setTexture(floor_t);
	//floor_s.setTextureRect(IntRect(4, 3, 31, 31));
	//floor_s.setPosition(0, 0);
	new_sprite.setTexture(texture);
	new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
	new_sprite.setPosition(150, 150);
	bool action = false;


	RenderWindow window(VideoMode(24*32, 20*32), "SFML works!");

	float x = 0, y = 0;
	double CurrentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 500;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type = Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::P)
					speed += 0.001;

			}
		}
		check_x = new_sprite.getPosition().x;
		check_y = new_sprite.getPosition().y;
		if (sf::Keyboard::isKeyPressed(Keyboard::Space) || action)
		{
			action = true;
			texture.loadFromImage(image2);
			CurrentFrame += (0.003 + speed)*time;
			if (CurrentFrame > 5) { action = false; texture.loadFromImage(image); }// åñëè ïðèøëè ê òðåòüåìó êàäðó - îòêèäûâàåìñÿ íàçàä.
			new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 64, 0, 64, 64));
		}
		if (!action)
		{

			if (sf::Keyboard::isKeyPressed(Keyboard::W))
			{
				new_sprite.move(0, -time / 12);
				CurrentFrame += 0.003*time;
				if (CurrentFrame > 6) CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 64, 32, 64));
			}
			else if (sf::Keyboard::isKeyPressed(Keyboard::S))
			{
				new_sprite.move(0, time / 12);
				CurrentFrame += 0.003*time;
				if (CurrentFrame > 6) CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 0, 32, 64));
			}

			else if (sf::Keyboard::isKeyPressed(Keyboard::A))
			{
				new_sprite.move(-time / 12, 0);
				CurrentFrame += 0.003*time;
				if (CurrentFrame > 6)  CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 128, 32, 64));
			}
			else if (sf::Keyboard::isKeyPressed(Keyboard::D))
			{
				new_sprite.move(time / 12, 0);
				CurrentFrame += 0.003*time;
				if (CurrentFrame > 6)  CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 192, 32, 64));
			}
			else
			{
				CurrentFrame = 1;
				new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
			}

			if (new_sprite.getPosition().x != check_x || new_sprite.getPosition().y != check_y)
			{
				if (checkPosition(map, new_sprite.getPosition().x, new_sprite.getPosition().y))
					new_sprite.setPosition(check_x, check_y);
			}

		}




		window.clear();
		window.draw(rect);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (map[i][j] == '1')
				{
					brick.setTextureRect(IntRect(0, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (map[i][j] == '=')
				{
					brick.setTextureRect(IntRect(8*33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (map[i][j] == '2')
				{
					brick.setTextureRect(IntRect(7 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (map[i][j] == '3')
				{
					brick.setTextureRect(IntRect(4 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (map[i][j] == '4')
				{
					brick.setTextureRect(IntRect(11 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (map[i][j] == '|')
				{
					brick.setTextureRect(IntRect(2 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
					
				window.draw(brick);
			}
		}

		window.draw(new_sprite);
		window.display();
	}
}

//0 0 74 57



