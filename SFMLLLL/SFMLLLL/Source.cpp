#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{





	ContextSettings settings;
	Clock clock;
	Texture texture;
	Image image;
	image.loadFromFile("1.png");
	image.createMaskFromColor(Color(0, 255, 0));
	texture.loadFromImage(image);
	RectangleShape t;
	t.setTexture(&texture);
	t.setSize(Vector2f(100,100));
	t.setPosition(125, 125);
	

	RenderWindow window(VideoMode(800, 800), "SFML works!");
	CircleShape circle;

	circle.setRadius(50);
	circle.setPosition(50, 50);
	circle.setFillColor(Color::Red);
	RectangleShape rect[3];
	rect[0].setSize(Vector2f(300, 100));
	rect[0].setPosition(0, 0);
	rect[0].setFillColor(Color(0, 0, 255));

	rect[1].setSize(Vector2f(300, 100));
	rect[1].setPosition(0, 100);
	rect[1].setFillColor(Color(255, 0, 0));

	rect[2].setSize(Vector2f(300, 100));
	rect[2].setPosition(0, 200);
	rect[2].setFillColor(Color(0, 255, 0));



	float x = 0, y = 0;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 4000;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		settings.antialiasingLevel = 0;
		for (int i = 0; i < 3; i++)
		{
			if (sf::Keyboard::isKeyPressed(Keyboard::W))
			{
				rect[i].move(0, -time);
				t.move(0, -time);
			}
				
			if (sf::Keyboard::isKeyPressed(Keyboard::S))
			{
				rect[i].move(0, time);
				t.move(0, time);
			}
				
			if (sf::Keyboard::isKeyPressed(Keyboard::A))
			{
				rect[i].move(-time, 0);
				t.move(-time, 0);
			}
				
			if (sf::Keyboard::isKeyPressed(Keyboard::D))
			{
				rect[i].move(time, 0);
				t.move(time, 0);
			}
				
		}

		window.clear();
		for (int i = 0; i < 3; i++)
		{
			window.draw(rect[i]);
		}
		window.draw(t);
		window.display();
	}

	return 0;
}