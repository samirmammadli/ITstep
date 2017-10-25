#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Direction { Up, Down, Left, Right };
enum State { Idle, Attack, Defend, Shoot, Dead };
enum MapCell { Empty, Wall, Hole };

class Character;
