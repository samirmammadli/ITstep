#include "Zombie.h"

class Map 
{
	vector<vector<MapCell>> field;
	Map()
	{
		field.resize(height);
		for (int i = 0; i < height; i++)
		{
			field[i].resize(width);
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int code = rand() % 55;
				if (i == 0 || i == height - 1)
					field[i][j] = MapCell::Wall;
				else if (j == 0 || j == width - 1 || code < 2)
					field[i][j] = MapCell::Wall;
				else 
					field[i][j] = MapCell::Empty;
			}
		}
	}
public:
	static const int width;
	static const int height;

	static Map& get()
	{
		static Map INSTANCE;
		return INSTANCE;
	}

	MapCell getCell(int x, int y)
	{
		if (x >= 0 && x < height && y >= 0 && y < width)
			return field[x][y];
		else
			return MapCell::Wall;
	}
};


const int Map::width = field_width;
const int Map::height = field_height;