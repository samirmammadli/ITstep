#pragma once
#include "Map.h"

class Game
{
	Map& map;
	Player& player;
	vector<GameObject> staticObjects;
	vector<Enemy> enemies;
};

