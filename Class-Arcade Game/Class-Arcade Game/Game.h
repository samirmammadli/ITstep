#pragma once
#include "Map.h"

class Game
{
	Map& map;
	Player& player;
	vector<GameObject> staticObjects;
	vector<Enemy> enemies;
public:
	Game(Player &p) : map(Map::get()), player(p) {}
	void  DrawMap()
	{
		for (int i = 0; i < Map::height; i++)
		{
			for (int j = 0; j < Map::width; j++)
			{
				if (map.getCell(i, j) == Wall)
					cout << '#';
				else
					cout << ' ';
			}
			cout << endl;
		}
	}
};

