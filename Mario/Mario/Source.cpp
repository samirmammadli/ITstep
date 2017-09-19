#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size*N;
int h = size*M;

int dir, num = 4;

struct Snake
{
	int x, y;
}  s[100];

struct Fruct
{
	int x, y;
} f;

void Tick()
{
	for (int i = num; i>0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (dir == 0) s[0].y += 1;
	if (dir == 1) s[0].x -= 1;
	if (dir == 2) s[0].x += 1;
	if (dir == 3) s[0].y -= 1;

	if ((s[0].x == f.x) && (s[0].y == f.y))
	{
		num++;
		f.x = rand() % N;
		f.y = rand() % M;
	}

	if (s[0].x>N) s[0].x = 0;  if (s[0].x<0) s[0].x = N;
	if (s[0].y>M) s[0].y = 0;  if (s[0].y<0) s[0].y = M;

	/*for (int i = 1; i<num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)  num = i;*/
}

int main()
{
	srand(time(0));

	RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1, t2;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);

	Clock clock;
	float timer = 0, delay = 0.1;

	f.x = 10;
	f.y = 10;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right))  dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 0;

		if (timer>delay) { timer = 0; Tick(); }

		////// draw  ///////
		window.clear();

		for (int i = 0; i<N; i++)
			for (int j = 0; j<M; j++)
			{
				sprite1.setPosition(i*size, j*size);  window.draw(sprite1);
			}

		for (int i = 0; i<num; i++)
		{
			sprite2.setPosition(s[i].x*size, s[i].y*size);  window.draw(sprite2);
		}

		sprite2.setPosition(f.x*size, f.y*size);  window.draw(sprite2);

		window.display();
	}

	return 0;
}















//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <conio.h>
//using namespace sf;
//using namespace std;
//
//
//struct PointS {
//	int x;
//	int y;
//};
//
//class Figures {
//	Image image;
//	Texture block_texture;
//	Sprite* figures = nullptr;
//public:
//	Figures()
//	{
//		this->image.loadFromFile("images/figures.jpg");
//		this->block_texture.loadFromImage(image);
//		this->figures = new Sprite[4];
//		for (int i = 0; i < 4; i++)
//		{
//			figures[i].setTexture(block_texture);
//		}
//	}
//	void SetPosition(PointS coords[4])
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			figures[i].setPosition(coords[i].x, coords[i].y);
//		}
//	}
//	Sprite& Getfig(int index)
//	{
//		return figures[index];
//	}
//
//	void move(int x, int y)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			figures[i].move(x, y);
//		}
//		
//	}
//	void rotate()
//	{
//		PointS b;
//		b.x = figures[1].getPosition().x;
//		b.y = figures[1].getPosition().y;
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 1) continue;
//			int x = figures[i].getPosition().x;
//			int y = figures[i].getPosition().y;
//
//			if (x < b.x && y < b.y)
//				figures[i].move(32, 0);
//			else if (x < b.x && y == b.y)
//				figures[i].move(16, -16);
//			else if (x < b.x && y > b.y)
//				figures[i].move(0, -32);
//			else if (x > b.x && y > b.y)
//				figures[i].move(-32, 0);
//			else if (x > b.x && y == b.y)
//				figures[i].move(-16, 16);
//			else if (x > b.x && y < b.y)
//				figures[i].move(0, 32);
//			else if (x == b.x && y < b.y)
//				figures[i].move(16, 16);
//			else if (x == b.x && y > b.y)
//				figures[i].move(-16, -16);
//		}
//	}
//};
//
//
//
//int main()
//{
//	Clock clock;
//	RenderWindow window(sf::VideoMode(800, 600), "Lesson 5. kychka-pc.ru");
//
//	int a = 0;
//
//
//	PointS * fig = new PointS[4];
//
//
//	//T
//	fig[0].x = 32;
//	fig[0].y = 16;
//
//	fig[1].x = 32;
//	fig[1].y = 32;
//
//	fig[2].x = 32;
//	fig[2].y = 48;
//
//	fig[3].x = 48;
//	fig[3].y = 32;
//
//	//Z
//	fig[0].x = 32;
//	fig[0].y = 16;
//
//	fig[2].x = 48;
//	fig[2].y = 32;
//
//	fig[3].x = 48;
//	fig[3].y = 48;
//
//
//	////L
//	//fig[0].x = 32;
//	//fig[0].y = 16;
//
//	//fig[2].x = 32;
//	//fig[2].y = 48;
//
//	//fig[3].x = 16;
//	//fig[3].y = 48;
//
//
//
//	Figures fig1;
//	fig1.SetPosition(fig);
//
//	Image image;
//	image.loadFromFile("images/tiles.png");
//
//	bool pause = false;
//	//image.createMaskFromColor(Color(255, 255, 255));
//
//	Texture herotexture;
//	herotexture.loadFromImage(image);
//
//	Sprite herosprite;
//	herosprite.setTexture(herotexture);
//	herosprite.setTextureRect(IntRect(0, 0, 16, 16));//получили нужный нам прямоугольник с котом
//	herosprite.setPosition(400, 0); //выводим спрайт в позицию x y 
//	//herosprite.setScale(0.5, 0.5);
//	//herosprite.setColor(Color(0, 255, 255));
//
//	float CurrentFrame = 0;
//	float time = 0;
//	sf::Event event;
//	float delay = 1;
//	float temp = 1;
//	while (window.isOpen())	
//	{
//
//		window.setKeyRepeatEnabled(false);
//			time += clock.getElapsedTime().asSeconds(); //дать прошедшее время в микросекундах
//			clock.restart(); //перезагружает время
//			time;
//		//cout << time << endl;
//			
//			(window.pollEvent(event));
//			
//				if (event.type == sf::Event::Closed)
//					window.close();
//				else if (event.type == sf::Event::KeyPressed)
//				{
//					if (event.key.code == sf::Keyboard::A)
//						fig1.move(-30, 0);
//					else if (event.key.code == sf::Keyboard::D)
//						fig1.move(30, 0);
//					if (event.key.code == sf::Keyboard::W)
//						fig1.rotate();
//						//temp = delay -= 0.2;
//				}
//
//			
//
//		
//			
//			
//			time > delay ? (fig1.move(0, 17), time = 0) : 0;//происходит само движение персонажа влево
//			//delay = 0;
//				
//			if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)))
//			{
//				cout << delay << endl;
//				delay -= delay - 0.05;
//				cout << delay << endl;
//			}
//			if (event.type == Event::KeyReleased)
//				delay = temp;
//			
//
//		
//			window.clear();
//			for (int i = 0; i < 4; i++)
//			{
//				window.draw(fig1.Getfig(i));
//			}
//			window.display();
//			
//	}
//
//	return 0;
//	
//}






















































//if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
//	CurrentFrame += 0.02*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
//	if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
//											 //herosprite.setTextureRect(IntRect(190, 65, 65, 62)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
//	time >= 0.015 && herosprite.getPosition().x >= 0 ? (herosprite.move(-10, 0), time = 0) : 0;//происходит само движение персонажа влево
//}
//if (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))
//{
//	CurrentFrame += 0.02*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
//	if (CurrentFrame > 3) CurrentFrame -= 3;
//	//herosprite.setTextureRect(IntRect(255, 0, 65, 64));
//	herosprite.getPosition().x <= 770 ? herosprite.move(time, 0) : 0;// herosprite.setTextureRect(IntRect(0, 192, 96, 96)); //координата Y, на которой герой изображен идущем вправо равна 96+96=192
//}
//if (Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))
//{
//	CurrentFrame += 0.02*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
//	if (CurrentFrame > 3) CurrentFrame -= 3;
//	//herosprite.setTextureRect(IntRect(190, 0, 65, 65));
//	herosprite.getPosition().y >= 0 ? herosprite.move(0, -time) : 0;// herosprite.setTextureRect(IntRect(0, 192, 96, 96)); //координата Y, на которой герой изображен идущем вправо равна 96+96=192
//}
//if (Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))
//{
//	CurrentFrame += 0.02*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
//	if (CurrentFrame > 3) CurrentFrame -= 3;
//	//herosprite.setTextureRect(IntRect(258, 65, 65, 64));
//	herosprite.getPosition().y < 570 ? herosprite.move(0, time) : 0;// herosprite.setTextureRect(IntRect(0, 192, 96, 96)); //координата Y, на которой герой изображен идущем вправо равна 96+96=192
//}
//if (Keyboard::isKeyPressed(Keyboard::Space))
//{
//	pause = true;
//}