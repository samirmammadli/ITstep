#include "Classes_SFML.h"


const int map_x = 55;
const int map_y = 50;


string maP[map_y] = {
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

bool checkPosition( const Sprite &person)
{
	IntRect size = person.getTextureRect();
	ObjectSize pos;
	pos.x = person.getPosition().x;
	pos.y = person.getPosition().y;
	
	if (pos.x / size.width < 0 || pos.x / 32>= map_x || pos.y / size.height < 0 || pos.y / 64 >= map_y)
		return true;
	
	pos.x1 = pos.x + size.width * person.getScale().x;
	pos.y1 = pos.y + size.height * person.getScale().y;
	pos.y2 = pos.y + size.height / 2 * person.getScale().y;
	pos.x1 /= 32;
	pos.y1 /= 32;
	pos.x /= 32;
	pos.y /= 32;
	pos.y2 /= 32;

	
	if (maP[pos.y][pos.x] != ' ')
		return true;
	if (maP[pos.y][pos.x1] != ' ')
		return true;
	if (maP[pos.y1][pos.x] != ' ')
		return true;
	if (maP[pos.y1][pos.x1] != ' ')
		return true;
	if (maP[pos.y2][pos.x] != ' ')
		return true;
	if (maP[pos.y2][pos.x1] != ' ')
		return true;

	return false;
}


bool CheckCollision(const sf::FloatRect &obj1,  sf::FloatRect const &obj2)
{
	sf::Rect<float> r1 = obj2;
	sf::Rect<float> r2 = obj1;
	return r1.intersects(r2);
}

void ChangePos(Direction &dir)
{
	int random = rand() % 500;
	if (random == 1)
		dir = Direction(rand() % 4);

}

void SearchForHero(const sf::Sprite &hero, const sf::Sprite &enemy)
{
	for (int i = 0; i < 10; i++)
	{
		0;
	}
}

void FollowHero(const sf::Sprite &hero, sf::Sprite &enemy, float time, Direction &dir)
{
	int x_range = enemy.getPosition().x - hero.getPosition().x;
	int  y_range = enemy.getPosition().y - hero.getPosition().y;

	if (!(hero.getGlobalBounds().intersects(enemy.getGlobalBounds())))
	{
		if (abs(x_range) > abs(y_range))
		{
			if (x_range > 0) { time *= -1; dir = Left; }
			else dir = Right;
			enemy.move(time / 17, 0);
		}
		else
		{
			if (y_range > 0) { time *= -1; dir = Up; }
			else dir = Down;
			enemy.move(0, time / 17);
		}
			
	}

}

void ScorpAnimation(Sprite &scorpion,const Direction &dir, float &scorpFrame, float time)
{
	if (dir == Up)
	{
		scorpFrame += 0.002*time;
		if (scorpFrame > 6) scorpFrame -= 6;
		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 96, 32, 32));
	}
	else if (dir == Down)
	{
		scorpFrame += 0.002*time;
		if (scorpFrame > 6) scorpFrame -= 6;
		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 30, 32, 32));
	}
	else if (dir == Left)
	{
		scorpFrame += 0.002*time;
		if (scorpFrame > 6) scorpFrame -= 6;
		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 160, 32, 32));

	}
	if (dir == Right)
	{
		scorpFrame += 0.002*time;
		if (scorpFrame > 6) scorpFrame -= 6;
		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 224, 32, 32));
	}
}


void ifDamaged(Sprite &charact,const Direction &dir, float &time, float &otskok, State &state)
{
	otskok += time / 3;
	if (dir == Up)
		charact.move(0, -time / 3);
	else if (dir == Down)
		charact.move(0, time / 3);
	else if (dir == Left)
		charact.move(-time / 3, 0);
	else if (dir == Right)
		charact.move(time / 3, 0);
	if (int(otskok) % 5 == 0)
		charact.setColor(Color::Red);
	else if (int(otskok) % 2 == 0)
		charact.setColor(Color::White);
	if (otskok > 300)
	{
		charact.setColor(Color::White);
		otskok = 0;
		state = Idle;
	}
}

void main()
{


	LoadResources& res = LoadResources::Load();
	int height = VideoMode::getDesktopMode().height;
	int width = VideoMode::getDesktopMode().width;
	View view;
	view.reset(sf::FloatRect(0, 0, width, height));

	
	double speed = 0;

	
	

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
	scorpion.setPosition(600, 500);
	scorpion.setScale(1.5,1.5);
	
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
	//new_sprite.setScale(5, 5);
	bool action = false;


	Direction enemy_dir = Direction(rand() % 4);
	Direction hero_dir = Up;
	Direction attack_dir = Up;
	State enemy_state = Idle;
	State hero_state = Idle;
	float otskok = 0;
	int check_scorp_x;
	int check_scorp_y;
	
	RenderWindow window(VideoMode::getDesktopMode(), "SFML works!", Style::Fullscreen);
	float x = 0, y = 0;
	float CurrentFrame = 0;
	float scorpFrame = 0;
	float AttackFrame = 0;




	RectangleShape sword;
	sword.setSize(Vector2f(32,32));






	while (window.isOpen())
	{
		check_x = new_sprite.getPosition().x;
		check_y = new_sprite.getPosition().y;
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
		if (action)
		{
			if (CheckCollision(sword.getGlobalBounds(), scorpion.getGlobalBounds()))
			{
				enemy_state = Damaged;
				attack_dir = enemy_dir;
			}
		}

		if (CheckCollision(new_sprite.getGlobalBounds(), scorpion.getGlobalBounds()))
		{
			hero_state = Damaged;
			attack_dir = enemy_dir;
		}
		
		if (sf::Keyboard::isKeyPressed(Keyboard::Space) || action)
		{
			action = true;
			texture.loadFromImage(image2);
			AttackFrame += (0.004 + speed)*time;
			if (hero_dir == Left)
			{
				if (AttackFrame > 5) { action = false; texture.loadFromImage(image); AttackFrame = 0; }
				new_sprite.setTextureRect(IntRect(int(AttackFrame) * 64+64, 0, -64, 64));
			}
			else
			{
			if (AttackFrame > 5) { action = false; texture.loadFromImage(image); AttackFrame= 0;}
			new_sprite.setTextureRect(IntRect(int(AttackFrame) * 64, 0, 64, 64));
			}
		}
		else if (!action)
		{

			if (sf::Keyboard::isKeyPressed(Keyboard::W))
			{
				hero_dir = Up;
				new_sprite.move(0, -time / 6);
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 6) CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 64, 32, 64));
			}
			else if (sf::Keyboard::isKeyPressed(Keyboard::S))
			{
				hero_dir = Down;
				new_sprite.move(0, time / 6);
				CurrentFrame += 0.005*time;
				if (CurrentFrame > 6) CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 0, 32, 64));
			}

			else if (sf::Keyboard::isKeyPressed(Keyboard::A))
			{
				hero_dir = Left;
				new_sprite.move(-time / 6, 0);
				CurrentFrame += 0.008*time;
				if (CurrentFrame > 6)  CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 128, 32, 64));
			}
			else if (sf::Keyboard::isKeyPressed(Keyboard::D))
			{
				hero_dir = Right;
				new_sprite.move(time / 6, 0);
				CurrentFrame += 0.008*time;
				if (CurrentFrame > 6)  CurrentFrame -= 4;
				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 192, 32, 64));
			}
			else
			{
				CurrentFrame = 1;
				if (hero_dir == Down) new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
				else if (hero_dir == Up) new_sprite.setTextureRect(IntRect(0, 64, 32, 64));
				else if (hero_dir == Right) new_sprite.setTextureRect(IntRect(0, 192, 32, 64));
				else if (hero_dir == Left) new_sprite.setTextureRect(IntRect(0, 128, 32, 64));
			}

			
		
		}
		if (hero_state == Damaged)
		{
			ifDamaged(new_sprite, enemy_dir, time, otskok, hero_state);
		}

		if (new_sprite.getPosition().x != check_x || new_sprite.getPosition().y != check_y)
		{
			if (checkPosition(new_sprite))
				new_sprite.setPosition(check_x, check_y);
		}
		//Scorpion

		check_scorp_x = scorpion.getPosition().x;
		check_scorp_y = scorpion.getPosition().y;
		if (enemy_state != Damaged && enemy_state != Follow)
		{
			ChangePos(enemy_dir);
			if (enemy_dir == Up)
			{
				scorpion.move(0, -time / 25);
				
			}
			else if (enemy_dir == Down)
			{
				scorpion.move(0, time / 25);
			}
			else if (enemy_dir == Left)
			{
				scorpion.move(-time / 25, 0);

			}
			if (enemy_dir == Right)
			{
				scorpion.move(time / 25, 0);
			}
		}
		
		if (enemy_state == Damaged)
		{
			ifDamaged(scorpion, hero_dir, time, otskok, enemy_state);
		}
		else FollowHero(new_sprite, scorpion, time, enemy_dir); 
		 ScorpAnimation(scorpion, enemy_dir, scorpFrame, time);

		

		





		if (scorpion.getPosition().x != check_scorp_x || scorpion.getPosition().y != check_scorp_y)
		{
			if (checkPosition(scorpion))
			{
				scorpion.setPosition(check_scorp_x, check_scorp_y);
				enemy_dir = Direction(rand() % 4);
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
				if (maP[i][j] == '1')
				{
					brick.setTextureRect(IntRect(0, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (maP[i][j] == '=')
				{
					brick.setTextureRect(IntRect(8*33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (maP[i][j] == '2')
				{
					brick.setTextureRect(IntRect(7 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (maP[i][j] == '3')
				{
					brick.setTextureRect(IntRect(4 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (maP[i][j] == '4')
				{
					brick.setTextureRect(IntRect(11 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
				else if (maP[i][j] == '|')
				{
					brick.setTextureRect(IntRect(2 * 33, 33, 32, 32));
					brick.setPosition(j * 32, i * 32);
				}
					
				window.draw(brick);
			}
		}



		if (hero_dir == Up)
			sword.setPosition(new_sprite.getPosition().x, new_sprite.getPosition().y -16);
		else if (hero_dir == Down)
			sword.setPosition(new_sprite.getPosition().x, new_sprite.getPosition().y + 48);
		else if (hero_dir == Left)
			sword.setPosition(new_sprite.getPosition().x - 8, new_sprite.getPosition().y + 16);
		else if (hero_dir == Right)
			sword.setPosition(new_sprite.getPosition().x + 40, new_sprite.getPosition().y + 16);
		
		window.draw(scorpion);
		window.draw(new_sprite);
		window.display();
	}
}

//0 0 74 57



















//#include "Classes.h"
//using namespace sf;
//
//
//
//const int map_x = 55;
//const int map_y = 50;
//
//
//string maP[map_y] = {
//	"1=====================================================2",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|      ========2                                      |",
//	"|              |                                      |",
//	"|              |                                      |",
//	"|              |           1===                       |",
//	"|              |           |                          |",
//	"|              |           |                          |",
//	"|              |           |                          |",
//	"|              3===========4                          |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"|                                                     |",
//	"3=====================================================4"
//};
//
//bool checkPosition(const Sprite &person)
//{
//	IntRect size = person.getTextureRect();
//	ObjectSize pos;
//	pos.x = person.getPosition().x;
//	pos.y = person.getPosition().y;
//
//	if (pos.x / size.width < 0 || pos.x / 32 >= map_x || pos.y / size.height < 0 || pos.y / 64 >= map_y)
//		return true;
//
//	pos.x1 = pos.x + size.width * person.getScale().x;
//	pos.y1 = pos.y + size.height * person.getScale().y;
//	pos.y2 = pos.y + size.height / 2 * person.getScale().y;
//	pos.x1 /= 32;
//	pos.y1 /= 32;
//	pos.x /= 32;
//	pos.y /= 32;
//	pos.y2 /= 32;
//
//
//	if (maP[pos.y][pos.x] != ' ')
//		return true;
//	if (maP[pos.y][pos.x1] != ' ')
//		return true;
//	if (maP[pos.y1][pos.x] != ' ')
//		return true;
//	if (maP[pos.y1][pos.x1] != ' ')
//		return true;
//	if (maP[pos.y2][pos.x] != ' ')
//		return true;
//	if (maP[pos.y2][pos.x1] != ' ')
//		return true;
//
//	return false;
//}
//
//
////void getCoords(const Sprite &person, ObjectSize &pos)
////{
////	IntRect size = person.getTextureRect();
////	pos.x = person.getPosition().x;
////	pos.y = person.getPosition().y;
////	pos.x1 = pos.x + size.width * person.getScale().x;
////	pos.y1 = pos.y + size.height * person.getScale().y;
////	pos.y2 = pos.y + size.height / 2 * person.getScale().y;
////}
//
//bool CheckCollision(const sf::Sprite &hero, const sf::Sprite &enemy)
//{
//	sf::Rect<float> r1 = enemy.getGlobalBounds();
//	sf::Rect<float> r2 = hero.getGlobalBounds();
//	return r1.intersects(r2);
//}
//
//void ChangePos(Direction &dir)
//{
//	int random = rand() % 500;
//	if (random == 1)
//		dir = Direction(rand() % 4);
//
//}
//
//void SearchForHero(const sf::Sprite &hero, const sf::Sprite &enemy)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		0;
//	}
//}
//
//void FollowHero(const sf::Sprite &hero, sf::Sprite &enemy, float time, Direction &dir)
//{
//	int x_range = enemy.getPosition().x - hero.getPosition().x;
//	int  y_range = enemy.getPosition().y - hero.getPosition().y;
//
//	if (!(hero.getGlobalBounds().intersects(enemy.getGlobalBounds())))
//	{
//		if (abs(x_range) > abs(y_range))
//		{
//			if (x_range > 0) { time *= -1; dir = Left; }
//			else dir = Right;
//			enemy.move(time / 14, 0);
//		}
//		else
//		{
//			if (y_range > 0) { time *= -1; dir = Up; }
//			else dir = Down;
//			enemy.move(0, time / 14);
//		}
//
//	}
//
//}
//
//void ScorpAnimation(Sprite &scorpion, const Direction &dir, float &scorpFrame, float time)
//{
//	if (dir == Up)
//	{
//		scorpFrame += 0.002*time;
//		if (scorpFrame > 6) scorpFrame -= 6;
//		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 96, 32, 32));
//	}
//	else if (dir == Down)
//	{
//		scorpFrame += 0.002*time;
//		if (scorpFrame > 6) scorpFrame -= 6;
//		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 30, 32, 32));
//	}
//	else if (dir == Left)
//	{
//		scorpFrame += 0.002*time;
//		if (scorpFrame > 6) scorpFrame -= 6;
//		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 160, 32, 32));
//
//	}
//	if (dir == Right)
//	{
//		scorpFrame += 0.002*time;
//		if (scorpFrame > 6) scorpFrame -= 6;
//		scorpion.setTextureRect(IntRect(int(scorpFrame) * 32, 224, 32, 32));
//	}
//}
//
//
//void ifDamaged(Sprite &charact, const Direction &dir, float &time, float &otskok, State &state)
//{
//	otskok += time / 3;
//	charact.setColor(Color::Red);
//	if (dir == Up)
//		charact.move(0, -time / 3);
//	else if (dir == Down)
//		charact.move(0, time / 3);
//	else if (dir == Left)
//		charact.move(-time / 3, 0);
//	else if (dir == Right)
//		charact.move(time / 3, 0);
//	if (int(otskok) % 5 == 0)
//		charact.setColor(Color::Red);
//	else if (int(otskok) % 2 == 0)
//		charact.setColor(Color::White);
//	if (otskok > 300)
//	{
//		charact.setColor(Color::White);
//		otskok = 0;
//		state = Idle;
//	}
//}
//
//void main()
//{
//	int height = VideoMode::getDesktopMode().height;
//	int width = VideoMode::getDesktopMode().width;
//	View view;
//	view.reset(sf::FloatRect(0, 0, width, height));
//
//
//	double speed = 0;
//
//
//
//
//	int temp_x;
//	int temp_y;
//	double check_x;
//	double check_y;
//	Texture Grass;
//	Grass.loadFromFile("images\\grass.jpg");
//	Clock clock;
//	Texture texture;
//	Texture Scorp;
//	Scorp.loadFromFile("images\\scorpion.png");
//	Sprite scorpion;
//	scorpion.setTexture(Scorp);
//	scorpion.setTextureRect(IntRect(0, 32, 32, 32));
//	scorpion.setPosition(200, 200);
//	scorpion.setScale(1.5, 1.5);
//
//	RectangleShape rect;
//	rect.setTexture(&Grass);
//	rect.setSize(Vector2f(512, 512));
//	Image image;
//	Image image2;
//	Texture Brick;
//	Brick.loadFromFile("images\\map.png");
//	Sprite brick;
//	brick.setTexture(Brick);
//	brick.setTextureRect(IntRect(528, 0, 32, 32));
//	image2.loadFromFile("images\\hero_attack.png");
//	image.loadFromFile("images\\hero_action.png");
//	texture.loadFromImage(image);
//	Sprite new_sprite;
//	new_sprite.setTexture(texture);
//	new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
//	new_sprite.setPosition(150, 150);
//	bool action = false;
//
//
//	Direction enemy_dir = Direction(rand() % 4);
//	Direction hero_dir = Up;
//	Direction attack_dir = Up;
//	State enemy_state = Idle;
//	State hero_state = Idle;
//	float otskok = 0;
//	int check_scorp_x;
//	int check_scorp_y;
//
//	RenderWindow window(VideoMode::getDesktopMode(), "SFML works!", Style::Fullscreen);
//	float x = 0, y = 0;
//	float CurrentFrame = 0;
//	float scorpFrame = 0;
//	float AttackFrame = 0;
//	while (window.isOpen())
//	{
//		check_x = new_sprite.getPosition().x;
//		check_y = new_sprite.getPosition().y;
//		float time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//		time /= 500;
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			else if (event.type = Event::KeyPressed)
//			{
//				if (event.key.code == sf::Keyboard::P)
//					speed += 0.001;
//			}
//		}
//		if (CheckCollision(new_sprite, scorpion))
//		{
//			hero_state = Damaged;
//			attack_dir = enemy_dir;
//		}
//
//		if (sf::Keyboard::isKeyPressed(Keyboard::Space) || action)
//		{
//			action = true;
//			texture.loadFromImage(image2);
//			AttackFrame += (0.004 + speed)*time;
//			if (hero_dir == Left)
//			{
//				if (AttackFrame > 5) { action = false; texture.loadFromImage(image); AttackFrame = 0; }
//				new_sprite.setTextureRect(IntRect(int(AttackFrame) * 64 + 64, 0, -64, 64));
//			}
//			else
//			{
//				if (AttackFrame > 5) { action = false; texture.loadFromImage(image); AttackFrame = 0; }
//				new_sprite.setTextureRect(IntRect(int(AttackFrame) * 64, 0, 64, 64));
//			}
//		}
//		else if (!action)
//		{
//
//			if (sf::Keyboard::isKeyPressed(Keyboard::W))
//			{
//				hero_dir = Up;
//				new_sprite.move(0, -time / 6);
//				CurrentFrame += 0.005*time;
//				if (CurrentFrame > 6) CurrentFrame -= 4;
//				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 64, 32, 64));
//			}
//			else if (sf::Keyboard::isKeyPressed(Keyboard::S))
//			{
//				hero_dir = Down;
//				new_sprite.move(0, time / 6);
//				CurrentFrame += 0.005*time;
//				if (CurrentFrame > 6) CurrentFrame -= 4;
//				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 0, 32, 64));
//			}
//
//			else if (sf::Keyboard::isKeyPressed(Keyboard::A))
//			{
//				hero_dir = Left;
//				new_sprite.move(-time / 6, 0);
//				CurrentFrame += 0.008*time;
//				if (CurrentFrame > 6)  CurrentFrame -= 4;
//				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 128, 32, 64));
//			}
//			else if (sf::Keyboard::isKeyPressed(Keyboard::D))
//			{
//				hero_dir = Right;
//				new_sprite.move(time / 6, 0);
//				CurrentFrame += 0.008*time;
//				if (CurrentFrame > 6)  CurrentFrame -= 4;
//				new_sprite.setTextureRect(IntRect(int(CurrentFrame) * 32, 192, 32, 64));
//			}
//			else
//			{
//				CurrentFrame = 1;
//				if (hero_dir == Down) new_sprite.setTextureRect(IntRect(0, 0, 32, 64));
//				else if (hero_dir == Up) new_sprite.setTextureRect(IntRect(0, 64, 32, 64));
//				else if (hero_dir == Right) new_sprite.setTextureRect(IntRect(0, 192, 32, 64));
//				else if (hero_dir == Left) new_sprite.setTextureRect(IntRect(0, 128, 32, 64));
//			}
//
//
//
//		}
//		if (hero_state == Damaged)
//		{
//			ifDamaged(new_sprite, enemy_dir, time, otskok, hero_state);
//		}
//
//		if (new_sprite.getPosition().x != check_x || new_sprite.getPosition().y != check_y)
//		{
//			if (checkPosition(new_sprite))
//				new_sprite.setPosition(check_x, check_y);
//		}
//		//Scorpion
//
//		check_scorp_x = scorpion.getPosition().x;
//		check_scorp_y = scorpion.getPosition().y;
//		if (enemy_state != Damaged && enemy_state != Follow)
//		{
//			ChangePos(enemy_dir);
//			if (enemy_dir == Up)
//			{
//				scorpion.move(0, -time / 25);
//
//			}
//			else if (enemy_dir == Down)
//			{
//				scorpion.move(0, time / 25);
//			}
//			else if (enemy_dir == Left)
//			{
//				scorpion.move(-time / 25, 0);
//
//			}
//			if (enemy_dir == Right)
//			{
//				scorpion.move(time / 25, 0);
//			}
//		}
//
//
//		FollowHero(new_sprite, scorpion, time, enemy_dir);
//		ScorpAnimation(scorpion, enemy_dir, scorpFrame, time);
//
//
//
//
//
//
//
//
//		if (scorpion.getPosition().x != check_scorp_x || scorpion.getPosition().y != check_scorp_y)
//		{
//			if (checkPosition(scorpion))
//			{
//				scorpion.setPosition(check_scorp_x, check_scorp_y);
//				enemy_dir = Direction(rand() % 4);
//			}
//		}
//		/////////////////////////////////////////////
//
//
//
//
//		temp_x = new_sprite.getPosition().x;
//		temp_y = new_sprite.getPosition().y;
//		if (temp_x < width / 2)
//			temp_x = width / 2;
//		if (temp_y < height / 2)
//			temp_y = height / 2;
//		if (temp_x > map_x * 32 - width / 2)
//			temp_x = map_x * 32 - width / 2;
//		if (temp_y > map_y * 32 - height / 2)
//			temp_y = map_y * 32 - height / 2;
//
//
//		view.setCenter(temp_x, temp_y);
//		window.setView(view);
//
//		window.clear();
//		for (int i = 0; i < 4; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				rect.setPosition(j * 512, i * 512);
//				window.draw(rect);
//			}
//		}
//
//
//		for (int i = 0; i < map_y; i++)
//		{
//			for (int j = 0; j < map_x; j++)
//			{
//				if (maP[i][j] == '1')
//				{
//					brick.setTextureRect(IntRect(0, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//				else if (maP[i][j] == '=')
//				{
//					brick.setTextureRect(IntRect(8 * 33, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//				else if (maP[i][j] == '2')
//				{
//					brick.setTextureRect(IntRect(7 * 33, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//				else if (maP[i][j] == '3')
//				{
//					brick.setTextureRect(IntRect(4 * 33, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//				else if (maP[i][j] == '4')
//				{
//					brick.setTextureRect(IntRect(11 * 33, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//				else if (maP[i][j] == '|')
//				{
//					brick.setTextureRect(IntRect(2 * 33, 33, 32, 32));
//					brick.setPosition(j * 32, i * 32);
//				}
//
//				window.draw(brick);
//			}
//		}
//
//		window.draw(scorpion);
//		window.draw(new_sprite);
//		window.display();
//	}
//}
//
////0 0 74 57



//#include <queue>
//using namespace std;
//
///* нахождение пути*/
//void find_path(int n, int row, int col, char** lab, int** visited, int** path, queue<int>& plan) {
//	if (!visited[row][col]) {
//		/* проверяем не вышли ли мы за границы лабиринта, есть ли клетка
//		в массиве посещенных и можно ли через нее пройти*/
//		if ((row + 1) < n && (row + 1) >= 0 && !visited[row + 1][col] &&
//			(lab[row + 1][col] == '.' || lab[row + 1][col] == 'X')) {
//			path[row + 1][col] = path[row][col] + 1;
//			plan.push(row + 1);
//			plan.push(col);
//		}
//		if ((row - 1) < n && (row - 1) >= 0 && !visited[row - 1][col] &&
//			(lab[row - 1][col] == '.' || lab[row - 1][col] == 'X')) {
//			path[row - 1][col] = path[row][col] + 1;
//			plan.push(row - 1);
//			plan.push(col);
//		}
//		if ((col + 1) < n && (col + 1) >= 0 && !visited[row][col + 1] &&
//			(lab[row][col + 1] == '.' || lab[row][col + 1] == 'X')) {
//			path[row][col + 1] = path[row][col] + 1;
//			plan.push(row);
//			plan.push(col + 1);
//		}
//		if ((col - 1) < n && (col - 1) >= 0 && !visited[row][col - 1] &&
//			(lab[row][col - 1] == '.' || lab[row][col - 1] == 'X')) {
//			path[row][col - 1] = path[row][col] + 1;
//			plan.push(row);
//			plan.push(col - 1);
//		}
//		visited[row][col] = 1; /* отмечаем клетку в которой побывали */
//	}
//}
//
//int main() {
//	int n, x_start, y_start, x_end, y_end, x, y;
//	queue <int> plan;
//	cin >> n;
//	char** lab = new char*[n];
//	int** visited = new int *[n];
//	int** path = new int *[n];
//	for (int i = 0; i<n; i++) {
//		lab[i] = new char[n];   /* массив для хранения лабиринта */
//		visited[i] = new int[n]; /* массив для хранения информации о посещении клеток*/
//		path[i] = new int[n];  /* массив для хранения найденных путей */
//		for (int j = 0; j<n; j++) {
//			visited[i][j] = 0;
//			path[i][j] = -1;
//			cin >> lab[i][j];
//			if (lab[i][j] == '@') { /* находим начало пути*/
//				x_start = i;
//				y_start = j;
//				plan.push(i);  /* заносим начальную клетку */
//				plan.push(j);  /* в план посещения */
//				path[i][j] = 1;
//			}
//			else if (lab[i][j] == 'X') { /* находим конечную точку */
//				x_end = i;
//				y_end = j;
//			}
//		}
//	}
//	while (!plan.empty()) { /* пока очередь посещения клеток непустая*/
//		x = plan.front();
//		plan.pop();
//		y = plan.front();
//		plan.pop();
//		find_path(n, x, y, lab, visited, path, plan); /* продолжаем поиск пути*/
//	}
//	if (!visited[x_end][y_end]) {
//		cout << "N" << endl;
//	}
//	else {
//		cout << "Y" << endl;
//		x = x_end;
//		y = y_end;
//		lab[x][y] = '+';
//		while (path[x][y] != 2) { /* восстановление пути*/
//			if ((x - 1) >= 0 && (x - 1) < n && (path[x - 1][y] == path[x][y] - 1)) {
//				x = x - 1;
//				lab[x][y] = '+';
//			}
//			else if ((x + 1) >= 0 && (x + 1) < n && (path[x + 1][y] == path[x][y] - 1)) {
//				x = x + 1;
//				lab[x][y] = '+';
//			}
//			else if ((y - 1) >= 0 && (y - 1) < n && (path[x][y - 1] == path[x][y] - 1)) {
//				y = y - 1;
//				lab[x][y] = '+';
//			}
//			else if ((y + 1) >= 0 && (y + 1) < n && (path[x][y + 1] == path[x][y] - 1)) {
//				y = y + 1;
//				lab[x][y] = '+';
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << lab[i][j];
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}
