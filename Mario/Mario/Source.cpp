#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
using namespace sf;
using namespace std;




class Figures {
	Image image;
	Texture block_texture;
	Sprite* figures = nullptr;
public:
	Figures()
	{
		this->image.loadFromFile("images/figures.jpg");
		this->block_texture.loadFromImage(image);
		this->figures = new Sprite[4];
		for (int i = 0; i < 4; i++)
		{
			figures[i].setTexture(block_texture);
		}
	}
};



int main()
{
	Clock clock;
	RenderWindow window(sf::VideoMode(800, 600), "Lesson 5. kychka-pc.ru");
	
	int a = 0;



	Image image;
	image.loadFromFile("images/tiles.png");

	bool pause = false;
	//image.createMaskFromColor(Color(255, 255, 255));

	Texture herotexture;
	herotexture.loadFromImage(image);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 16, 16));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(400, 0); //выводим спрайт в позицию x y 
	//herosprite.setScale(0.5, 0.5);
	//herosprite.setColor(Color(0, 255, 255));


	std::cout << herosprite.getPosition().x << std::endl;
	std::cout << herosprite.getPosition().y << std::endl;
	float CurrentFrame = 0;
	float time = 0;
	sf::Event event;
	float delay = 1;
	float temp = 1;
	while (window.isOpen())	
	{

		window.setKeyRepeatEnabled(false);
			time += clock.getElapsedTime().asSeconds(); //дать прошедшее время в микросекундах
			clock.restart(); //перезагружает время
			time;
		//cout << time << endl;
			
			(window.pollEvent(event));
			
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::KeyPressed)
				{
					//if (event.key.code == sf::Keyboard::A)
					//	herosprite.getPosition().x > 0 ? herosprite.move(-30, 0) : 0; //15
					//else if (event.key.code == sf::Keyboard::D)
					//	herosprite.getPosition().x < 770 ? herosprite.move(30, 0) : 0;
					if (event.key.code == sf::Keyboard::W)
						temp = delay -= 0.2;
				}

			

		
			
			
			time > delay && herosprite.getPosition().y < 570 ? ((herosprite.move(0, 17)), time = 0) : 0;//происходит само движение персонажа влево
			//delay = 0;
				
			if (Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)))
			{
				cout << delay << endl;
				delay -= delay - 0.05;
				cout << delay << endl;
			}
			if (event.type == Event::KeyReleased)
				delay = temp;
			

		
			window.clear();
			window.draw(herosprite);
			window.display();
			
	}

	return 0;
	
}































































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