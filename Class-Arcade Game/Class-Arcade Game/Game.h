
#include "Map.h"

class Game
{
	Map& map;
	Player& player;
	CursorStart start;
	vector<GameObject> staticObjects;
	vector<Enemy> enemies;
public:
	Game(Player &p, int x, int y) : map(Map::get()), player(p) { start.x = x; start.y = y; }
	void  DrawMap()
	{
		for (int i = 0; i < map.height; i++)
		{
			for (int j = 0; j < map.width; j++)
			{
				COORDS(start.x + j, start.y + i);
				if (map.getCell(i, j) == Wall)
					cout << '#';
				else
					cout << ' ';
			}
		}
		COORDS(start.x + player.getPosition().x, start.y + player.getPosition().y);
		cout << 'X';
		for (int i = 0; i < enemies.size(); i++)
		{
			COORDS(start.x + enemies[i].getPosition().x, start.y + enemies[i].getPosition().y);
			cout << 'W';
		}
		COORDS(0, start.y + map.height);
	}
};

