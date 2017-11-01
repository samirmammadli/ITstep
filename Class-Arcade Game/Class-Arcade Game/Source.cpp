#include "Classes.h"
#include <SFML/Graphics.hpp>
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
const int map_x = 55;
const int map_y = 50;

bool checkPosition(string *map, const Sprite &person)
{
	IntRect size = person.getTextureRect();
	Position pos;
	pos.x = person.getPosition().x;
	pos.y = person.getPosition().y;
	
	if (pos.x / size.width < 0 || pos.x / 32>= map_x || pos.y / size.height < 0 || pos.y / 64 >= map_y)
		return true;
	
	int x1 = pos.x + size.width * person.getScale().x;
	int y1 = pos.y + size.height * person.getScale().y;
	int y2 = pos.y + size.height / 2 * person.getScale().y;
	x1 /= 32;
	y1 /= 32;
	pos.x /= 32;
	pos.y /= 32;
	y2 /= 32;

	
	if (map[pos.y][pos.x] != ' ')
		return true;
	if (map[pos.y][x1] != ' ')
		return true;
	if (map[y1][pos.x] != ' ')
		return true;
	if (map[y1][x1] != ' ')
		return true;
	if (map[y2][pos.x] != ' ')
		return true;
	if (map[y2][x1] != ' ')
		return true;

	return false;
}

void ChangePos(Direction &dir)
{
	int random = rand() % 500;
	if (random == 1)
		dir = Direction(rand() % 4);

}

void main()
{
	int height = VideoMode::getDesktopMode().height;
	int width = VideoMode::getDesktopMode().width;
	View view;
	//view.reset(sf::FloatRect(0, 0, 24*32, 20*32));
	view.reset(sf::FloatRect(0, 0, width, height));

	
	double speed = 0;

	
	string map[map_y] = {
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

	int temp_x;
	int temp_y;
	double check_x;
	double check_y;
	Texture Grass;
	Grass.loadFromFile("images\\grass.jpg");
	Clock clock;
	Texture texture;
	Texture Scorp;
	Scorp.loadFromFile("images\\scorpion.png");
	Sprite scorpion;
	scorpion.setTexture(Scorp);
	scorpion.setTextureRect(IntRect(0,32,32,32));
	scorpion.setPosition(120, 120);
	scorpion.setScale(2,2);
	
	RectangleShape rect;
	rect.setTexture(&Grass);
	rect.setSize(Vector2f(512, 512));
	Image image;
	Image image2;
	Texture Brick;
	Brick.loadFromFile("images\\map.png");
	Sprite brick;
	brick.setTexture(Brick);
	brick.setTextureRect(IntRect(528, 0, 32, 32));
	image2.loadFromFile("images\\hero_attack.png");
	image.loadFromFile("images\\hero_action.png");
	texture.loadFromImage(image);
	Sprite new_sprite;
	new_sprite.setTexture(texture);
	new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
	new_sprite.setPosition(150, 150);
	bool action = false;


	Direction dir = Direction(rand() % 4);
	int check_scorp_x;
	int check_scorp_y;
	
	RenderWindow window(VideoMode::getDesktopMode(), "SFML works!");//, Style::Fullscreen);
	//RenderWindow window(VideoMode(24*32, 20*32), "SFML works!");
	float x = 0, y = 0;
	float CurrentFrame = 0;
	float scorpFrame = 0;
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
				if (checkPosition(map, new_sprite))
					new_sprite.setPosition(check_x, check_y);
			}

		}

		//Scorpion

		check_scorp_x = scorpion.getPosition().x;
		check_scorp_y = scorpion.getPosition().y;
		ChangePos(dir);
		if (dir == Up)
		{
			scorpion.move(0, -time / 25);
			scorpFrame += 0.002*time;
			if (scorpFrame > 6) scorpFrame -= 6;
			scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 96, 32, 32));
			
		}
		else if (dir == Down)
		{
			scorpion.move(0, time / 25);
			scorpFrame += 0.002*time;
			if (scorpFrame > 6) scorpFrame -= 6;
			scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 32, 32, 32));
		}
		else if (dir == Left)
		{
			scorpion.move(-time / 25, 0);
			scorpFrame += 0.002*time;
			if (scorpFrame > 6) scorpFrame -= 6;
			scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 160, 32, 32));
			
		}
		if (dir == Right)
		{
			scorpion.move(time / 25, 0);
			scorpFrame += 0.002*time;
			if (scorpFrame > 6) scorpFrame -= 6;
			scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 224, 32, 32));
		}

		if (scorpion.getPosition().x != check_scorp_x || scorpion.getPosition().y != check_scorp_y)
		{
			if (checkPosition(map, scorpion))
			{
				scorpion.setPosition(check_scorp_x, check_scorp_y);
				dir = Direction(rand() % 4);
			}		
		}
		/////////////////////////////////////////////

		temp_x = new_sprite.getPosition().x;
		temp_y = new_sprite.getPosition().y;
		if (temp_x < width / 2)
			temp_x = width / 2;
		if (temp_y < height / 2)
			temp_y = height / 2;
		if (temp_x > map_x * 32 - width / 2)
			temp_x = map_x * 32 - width / 2;
		if (temp_y > map_y * 32 - height / 2)
			temp_y = map_y * 32 - height / 2;


			view.setCenter(temp_x, temp_y);

		
		window.setView(view);
		
		window.clear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				rect.setPosition(j * 512, i * 512);
				window.draw(rect);
			}
		}
		

		for (int i = 0; i < map_y; i++)
		{
			for (int j = 0; j < map_x; j++)
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

		window.draw(scorpion);
		window.draw(new_sprite);
		window.display();
	}
}

//0 0 74 57



