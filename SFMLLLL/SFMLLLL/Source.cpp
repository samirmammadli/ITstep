#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{





	ContextSettings settings;
	Clock clock;
	Texture texture;
	Image image;
	image.loadFromFile("F:\\chel.png");
	//image.createMaskFromColor(Color(0, 255, 0));
	texture.loadFromImage(image);
	Sprite new_sprite;
	new_sprite.setTexture(texture);
	new_sprite.setTextureRect(IntRect(0, 195, 65, 65));
	new_sprite.setPosition(20, 20);


	RenderWindow window(VideoMode(800, 800), "SFML works!");

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
				new_sprite.move(time, 0);
				CurrentFrame += 0.058*time; 
				if (CurrentFrame > 9) CurrentFrame  = 1; // если пришли к третьему кадру - откидываемся назад.
				new_sprite.setTextureRect(IntRect(64 * int(CurrentFrame), 192, 64, 64));
			}


		window.clear();
		
		window.draw(new_sprite);
		window.display();
	}

	return 0;
}