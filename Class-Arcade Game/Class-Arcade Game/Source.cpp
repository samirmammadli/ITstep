#include "Game.h"
//#include <SFML/Graphics.hpp>



/*
Files
const, final, override
smart pointers
*/

void main()
{
	srand(time(0));
	Player pet("Samir", 200, 5);
	Game game(pet);
	game.DrawMap();
	
}

//void main()
//{
//	
//	string map[20] = {
//		"000000000000000000000000",
//		"000000000000000000000000",
//		"000000000000000000000000",
//		"000000000000000000000000",
//		"000000000000000000000000",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"0                      0",
//		"000000000000000000000000"
//	};
//
//	Clock clock;
//	Texture texture;
//	//Texture floor_t;
//	Image image;
//	//Image floor;
//	//floor.loadFromFile("images\\5.png");
//	image.loadFromFile("images\\War.png");
//	//image.createMaskFromColor(Color(0, 255, 0));
//	//floor_t.loadFromImage(floor);
//	texture.loadFromImage(image);
//	Sprite new_sprite;
//	//Sprite floor_s;
//	//floor_s.setTexture(floor_t);
//	//floor_s.setTextureRect(IntRect(4, 3, 31, 31));
//	//floor_s.setPosition(0, 0);
//	new_sprite.setTexture(texture);
//	new_sprite.setTextureRect(IntRect(0, 6, 74, 55));
//	new_sprite.setPosition(50, 50);
//	new_sprite.setOrigin(28, 28);
//
//
//	RenderWindow window(VideoMode(1366, 768), "SFML works!");
//
//	float x = 0, y = 0;
//	double CurrentFrame = 0;
//	while (window.isOpen())
//	{
//		float time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//		time /= 500;
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(Keyboard::W))
//		{
//			new_sprite.move(0, -time / 12);
//			CurrentFrame += 0.002*time;
//			if (CurrentFrame > 5) CurrentFrame -=5; // åñëè ïðèøëè ê òðåòüåìó êàäðó - îòêèäûâàåìñÿ íàçàä.
//			new_sprite.setTextureRect(IntRect(0, 6 + int(CurrentFrame) * 55, 74, 55));
//
//		}
//
//		else if (sf::Keyboard::isKeyPressed(Keyboard::S))
//		{
//			new_sprite.move(0, time/12);
//			CurrentFrame += 0.002*time;
//			if (CurrentFrame > 5) CurrentFrame -= 5; // åñëè ïðèøëè ê òðåòüåìó êàäðó - îòêèäûâàåìñÿ íàçàä.
//			new_sprite.setTextureRect(IntRect(296, 6 + int(CurrentFrame) * 55, 74, 55));
//
//		}
//
//		else if (sf::Keyboard::isKeyPressed(Keyboard::A))
//		{
//			new_sprite.move(-time/ 12, 0);
//			CurrentFrame += 0.002*time;
//			if (CurrentFrame > 5)  CurrentFrame -= 5; // åñëè ïðèøëè ê òðåòüåìó êàäðó - îòêèäûâàåìñÿ íàçàä.
//			
//			new_sprite.setTextureRect(IntRect(148 + 74, int(CurrentFrame) * 55, -74, 55));
//
//		}
//
//		else if (sf::Keyboard::isKeyPressed(Keyboard::D))
//		{
//
//			new_sprite.move(time / 12, 0);
//			CurrentFrame += 0.002*time;
//			if (CurrentFrame > 5)  CurrentFrame -= 5; // åñëè ïðèøëè ê òðåòüåìó êàäðó - îòêèäûâàåìñÿ íàçàä.
//			new_sprite.setTextureRect(IntRect(148,  int(CurrentFrame) * 55, 74, 55));
//			
//		}
//		else
//		{
//			new_sprite.setTextureRect(IntRect(0, 0, 74, 57));
//		}
//
//
//		window.clear();
//
//	/*	for (int i = 0; i < 20; i++)
//		{
//			for (int j = 0; j < 25; j++)
//			{
//				if (map[i][j] == '0')
//					floor_s.setPosition(j * 31, i * 31);
//				window.draw(floor_s);
//			}
//		}*/
//		window.draw(new_sprite);
//		window.display();
//	}
//}
//
////0 0 74 57