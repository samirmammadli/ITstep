#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
int main()
{

	Clock clock;
	RenderWindow window(sf::VideoMode(640, 480), "Lesson 5. kychka-pc.ru");



	Texture herotexture;
	herotexture.loadFromFile("images/hero.png");

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 192, 96, 96));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(250, 250); //выводим спрайт в позицию x y 

	float CurrentFrame = 0;
	float time;
	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time  = time / 200; //скорость игры

		std::cout << time << "\n";//смотрим как живет время (перезагружается, как видим)
		sf::Event event;
		window.pollEvent(event);
		
			if (event.type == sf::Event::Closed)
				window.close();

				if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
					CurrentFrame += 0.002*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
					if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
					herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается начинаем рисование с координаты Х равной 0,96,96*2, и опять 0
					herosprite.move(-0.1*time, 0);//происходит само движение персонажа влево
				}
		if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.1*time, 0); herosprite.setTextureRect(IntRect(0, 192, 96, 96)); } //координата Y, на которой герой изображен идущем вправо равна 96+96=192
		if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.1*time); herosprite.setTextureRect(IntRect(0, 288, 96, 96)); } //координата Y на которой герой изображен идущим вверх равна 288
		if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.1*time); herosprite.setTextureRect(IntRect(0, 0, 96, 96)); } //координата 0, это верхняя часть изображения с героем, от нее и отталкиваемся ровными квадратиками по 96. 

			/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				herosprite.setColor(Color::Red);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				herosprite.setColor(Color::Color::Transparent);
			}*/
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}