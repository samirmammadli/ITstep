#pragma once
#include <iostream>
#include <windows.h>
// Allegro Library
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>



//Enum Values
enum GameMode {
	EASY,
	HARD
};

enum enemy_shooting {
	X_UP,
	X_DOWN,
	Y_UP,
	Y_DOWN
};

enum image_position {
	HORIZONTAL,
	VERTICAL
};

enum arrangement {
	MANUAL,
	RANDOM,
	CHECK
};

enum which_field {
	USER,
	ENEMY
};

enum Ship_State {
	ON_SUBFIELD,
	SELECTED,
	DRAWED
};


//Global Variables
bool damaged = false;
bool enemy_shoot = false;
int drawed_ships = 0;


//Constant Global Values
const int field_size = 10;
const int ships_count = 10;
const int img_pix_size = 40;
const int field1_x_indent = 50;
const int field1_y_indent = 50;
const int field2_x_indent = 700;
const int field2_y_indent = 50;
const int subfield1_x_indent = field1_x_indent;
const int subfield1_y_indent = field1_y_indent + field_size * img_pix_size + img_pix_size;
const int subfield2_x_indent = field2_x_indent;
const int subfield2_y_indent = field2_y_indent + field_size * img_pix_size + img_pix_size;


//Data section
ALLEGRO_DISPLAY* display = nullptr;
ALLEGRO_BITMAP* display_icon = nullptr;
ALLEGRO_BITMAP* ocean = nullptr;
ALLEGRO_BITMAP* aim = nullptr;
ALLEGRO_BITMAP* instructions = nullptr;
ALLEGRO_BITMAP* Table = nullptr;
ALLEGRO_BITMAP* Black = nullptr;
ALLEGRO_BITMAP* back = nullptr;
ALLEGRO_BITMAP* middle1 = nullptr;
ALLEGRO_BITMAP* middle2 = nullptr;
ALLEGRO_BITMAP* front = nullptr;
ALLEGRO_BITMAP* single = nullptr;
ALLEGRO_BITMAP* green_square = nullptr;
ALLEGRO_BITMAP* x_img = nullptr;
ALLEGRO_BITMAP* f_img = nullptr;
ALLEGRO_BITMAP* background = nullptr;
ALLEGRO_BITMAP* ships_field_image = nullptr;
ALLEGRO_BITMAP* red_square = nullptr;
ALLEGRO_FONT* font = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_EVENT event;


//Game Structures
struct enemy_shoot_settings
{
	GameMode mode = HARD;
	bool shooted = false;
	int count = 0;
	int random = 0;
	int ship = 4;
	int first_x;
	int first_y;
};


struct shoots
{
	int x = -1;
	int y = -1;
	enemy_shooting state;
};


struct subfield
{
	int x = -1;
	int y = -1;
};

struct Fields
{
	int ship = -1;
	bool state = false;
};

struct Ships
{
	int points = 0;
	int points_to_death = 0;
	int img_number = 0;
	Ship_State is_drawed = ON_SUBFIELD;
	image_position	ship_pos = HORIZONTAL;
	ALLEGRO_BITMAP** ship_image = new ALLEGRO_BITMAP*[4]{ nullptr };

};


void init_ships_params(Ships ships_arr[ships_count], ALLEGRO_BITMAP* back, ALLEGRO_BITMAP* middle1, ALLEGRO_BITMAP* middle2, ALLEGRO_BITMAP* front);
bool sort_ships(Ships field[ships_count], int x, int y, int &ship_number, arrangement, Fields bat_field[field_size][field_size], which_field player);
void DrawSelectedShip(Ships field[ships_count], int x, int y, int ship_number, Fields bat_field[field_size][field_size]);
void Draw_ships_on_field(Fields bat_field[field_size][field_size], Ships ships_arr[ships_count], which_field player);
void Ships_of_subfield(Ships ships_arr[field_size], which_field player, subfield SubfieldShips[ships_count][4], bool init = false);
void Selected_Ship(Ships ships_arr[field_size], int x, int y, int &ship_number, subfield SubfieldShips[ships_count][4]);
void DrawShoots(Ships ships_arr[ships_count], Fields bat_field[field_size][field_size], int x, int y, which_field player, int destroyed[2]);
void EnemyShoots(Ships ships_arr[ships_count], Fields bat_field[field_size][field_size], shoots shooting[5], enemy_shoot_settings &Settings, int destroyed[2]);


/*******************************************************************************************************************************************/

//Put ships on the field, and shows is selected ship position on the field right or wrong 

/*******************************************************************************************************************************************/
bool sort_ships(Ships ships_arr[ships_count], int x, int y, int &ship_number, arrangement Case, Fields bat_field[field_size][field_size], which_field player)
{
	if ((ship_number < 0 || ship_number > 9) && Case != RANDOM)
		return 0;
	bool is_place_empty = true;
	int steps = 1;
	int indent_x, indent_y;
	int count = ships_arr[ship_number].points;
	int temp_x;
	int temp_y;

	//Write enemy's or user's field indent
	player == USER ? (indent_x = field1_x_indent, indent_y = field1_y_indent) : (indent_x = field2_x_indent, indent_y = field2_y_indent);
	//Convert mouse coordinates to field cell coordinates
	if (x >= indent_x && y >= indent_y && x <= indent_x + field_size * img_pix_size && y <= indent_y + field_size * img_pix_size)
	{
		temp_x = (x - indent_x) / img_pix_size;
		temp_y = (y - indent_y) / img_pix_size;
	}
	else
	{
		temp_x = -1;
		temp_y = -1;
	}

	if (Case == RANDOM)
	{
		steps = 5000;
		ship_number = 0;
		for (int i = 0; i < field_size; i++)
		{
			for (int j = 0; j < field_size; j++)
			{
				bat_field[i][j].ship = -1;
			}
		}
	}

	for (int i = 0; ship_number < ships_count && i < steps; i++)
	{
		if (Case == RANDOM)
		{
			is_place_empty = true;
			count = ships_arr[ship_number].points;
			temp_x = rand() % 10;
			temp_y = rand() % 10;
			ships_arr[ship_number].ship_pos = image_position(rand() % 2);
		}
		if (ships_arr[ship_number].ship_pos == VERTICAL)
		{
			if (temp_y > 0)
			{
				bat_field[temp_y - 1][temp_x].ship != -1 ? is_place_empty = false : 0;
				if (temp_x > 0)
					bat_field[temp_y - 1][temp_x - 1].ship != -1 ? is_place_empty = false : 0;
				if (temp_x < field_size - 1)
					bat_field[temp_y - 1][temp_x + 1].ship != -1 ? is_place_empty = false : 0;

			}
			if (temp_y + count < field_size)
			{
				bat_field[temp_y + count][temp_x].ship != -1 ? is_place_empty = false : 0;
				if (temp_x > 0)
					bat_field[temp_y + count][temp_x - 1].ship != -1 ? is_place_empty = false : 0;
				if (temp_x < field_size - 1)
					bat_field[temp_y + count][temp_x + 1].ship != -1 ? is_place_empty = false : 0;
			}

			for (int i = 0; i < count && is_place_empty; i++)
			{
				if (temp_y + i >= 0 && temp_y + i < field_size && temp_x >= 0 && temp_x < field_size && bat_field[temp_y + i][temp_x].ship == -1)
				{
					if (temp_x > 0)
						bat_field[temp_y + i][temp_x - 1].ship != -1 ? is_place_empty = false : 0;
					if (temp_x < field_size - 1)
						bat_field[temp_y + i][temp_x + 1].ship != -1 ? is_place_empty = false : 0;
				}
				else
					is_place_empty = false;
			}
			for (int i = 0; i < ships_arr[ship_number].points && is_place_empty && Case != CHECK; i++)
			{
				bat_field[temp_y + i][temp_x].ship = ship_number;
			}
			if (is_place_empty && Case == RANDOM)
			{
				ships_arr[ship_number].is_drawed = ON_SUBFIELD;
				ship_number++;
				player == USER ? drawed_ships = 10 : 0;
			}
			else if (is_place_empty && Case == MANUAL)
			{
				ships_arr[ship_number].is_drawed = DRAWED;
				ship_number = -1;
				drawed_ships++;
			}
		}
		else if (ships_arr[ship_number].ship_pos == HORIZONTAL)
		{
			if (temp_x > 0)
			{
				bat_field[temp_y][temp_x - 1].ship != -1 ? is_place_empty = false : 0;
				if (temp_y > 0)
					bat_field[temp_y - 1][temp_x - 1].ship != -1 ? is_place_empty = false : 0;
				if (temp_y < field_size - 1)
					bat_field[temp_y + 1][temp_x - 1].ship != -1 ? is_place_empty = false : 0;

			}
			if (temp_x + count < field_size)
			{
				bat_field[temp_y][temp_x + count].ship != -1 ? is_place_empty = false : 0;
				if (temp_y > 0)
					bat_field[temp_y - 1][temp_x + count].ship != -1 ? is_place_empty = false : 0;
				if (temp_y < field_size - 1)
					bat_field[temp_y + 1][temp_x + count].ship != -1 ? is_place_empty = false : 0;
			}

			for (int i = 0; i < count; i++)
			{
				if (temp_y >= 0 && temp_y < field_size && temp_x + i >= 0 && temp_x + i < field_size && bat_field[temp_y][temp_x + i].ship == -1)
				{
					if (temp_y > 0)
						bat_field[temp_y - 1][temp_x + i].ship != -1 ? is_place_empty = false : 0;
					if (temp_y < field_size - 1)
						bat_field[temp_y + 1][temp_x + i].ship != -1 ? is_place_empty = false : 0;
				}
				else
					is_place_empty = false;
			}
			for (int i = 0; i < count && is_place_empty && Case != CHECK; i++)
			{
				bat_field[temp_y][temp_x + i].ship = ship_number;
			}
			if (is_place_empty && Case == RANDOM)
			{
				ships_arr[ship_number].is_drawed = ON_SUBFIELD;
				ship_number++;
				player == USER ? drawed_ships = 10 : 0;
			}
			else if (is_place_empty && Case == MANUAL)
			{
				ships_arr[ship_number].is_drawed = DRAWED;
				ship_number = -1;
				drawed_ships++;
			}
		}
	}

	if (Case == CHECK)
		return is_place_empty;
}
/*******************************************************************************************************************************************/

// Drawing and check Current Selected Ship for correct position of field 

/*******************************************************************************************************************************************/
void DrawSelectedShip(Ships ships_arr[ships_count], int x, int y, int ship_number, Fields bat_field[field_size][field_size])
{
	bool correct_position = sort_ships(ships_arr, x, y, ship_number, CHECK, bat_field, USER);
	if (ship_number < 0 || ship_number > 9)
		return;
	for (int i = 0; i < ships_arr[ship_number].points; i++)
	{
		if (ships_arr[ship_number].ship_pos == VERTICAL)
		{
			al_draw_rotated_bitmap(ships_arr[ship_number].ship_image[i], 0, 0, x + img_pix_size, y + i * img_pix_size, 1.566, 0);
			correct_position ? al_draw_bitmap(green_square, x, y + i * img_pix_size, 0) : al_draw_bitmap(red_square, x, y + i * img_pix_size, 0);
		}

		else
		{
			al_draw_bitmap(ships_arr[ship_number].ship_image[i], x + i * img_pix_size, y, 0);
			correct_position ? al_draw_bitmap(green_square, x + i * img_pix_size, y, 0) : al_draw_bitmap(red_square, x + i * img_pix_size, y, 0);
		}
	}
}
/*******************************************************************************************************************************************/

//Draw Ships on field						

/*******************************************************************************************************************************************/
void Draw_ships_on_field(Fields bat_field[field_size][field_size], Ships ships_arr[ships_count], which_field player)
{
	int curr_ship;
	int indent_x, indent_y;
	//Write enemy's or user's field indent
	player == USER ? (indent_x = field1_x_indent, indent_y = field1_y_indent) : (indent_x = field2_x_indent, indent_y = field2_y_indent);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			curr_ship = bat_field[i][j].ship;
			if (curr_ship >= 0 && curr_ship < ships_count)
			{
				int u = ships_arr[curr_ship].img_number;
				if (ships_arr[curr_ship].ship_pos == HORIZONTAL)
				{
					player == USER || ships_arr[curr_ship].points_to_death == 0 ? al_draw_bitmap(ships_arr[curr_ship].ship_image[u], j * img_pix_size + indent_x, i * img_pix_size + indent_y, 0) : 0;
				}
				else
				{
					player == USER || ships_arr[curr_ship].points_to_death == 0 ? al_draw_rotated_bitmap(ships_arr[curr_ship].ship_image[u], 0, 0, j * img_pix_size + indent_x + img_pix_size, i * img_pix_size + indent_y, 1.566, 0) : 0;
				}
				ships_arr[curr_ship].img_number++;

			}
			bat_field[i][j].state ? al_draw_bitmap(x_img, j * img_pix_size + indent_x, i * img_pix_size + indent_y, 0) : 0;
			curr_ship == 10 ? al_draw_bitmap(f_img, j * img_pix_size + indent_x, i * img_pix_size + indent_y, 0) : 0;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		ships_arr[i].img_number = 0;
	}
}
/*******************************************************************************************************************************************/

//Initializing User and Enemy Ships parameters	

/*******************************************************************************************************************************************/
void init_ships_params(Ships ships_arr[ships_count], ALLEGRO_BITMAP* back, ALLEGRO_BITMAP* middle1, ALLEGRO_BITMAP* middle2, ALLEGRO_BITMAP* front)
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			ships_arr[i].ship_image[0] = back;
			ships_arr[i].ship_image[1] = middle1;
			ships_arr[i].ship_image[2] = middle2;
			ships_arr[i].ship_image[3] = front;
			ships_arr[i].points = 4;
			ships_arr[i].points_to_death = 4;

		}
		else if (i == 1 || i == 2)
		{
			ships_arr[i].ship_image[0] = back;
			ships_arr[i].ship_image[1] = middle2;
			ships_arr[i].ship_image[2] = front;
			ships_arr[i].points = 3;
			ships_arr[i].points_to_death = 3;
		}
		else if (i > 2 && i < 6)
		{
			ships_arr[i].ship_image[0] = back;
			ships_arr[i].ship_image[1] = front;
			ships_arr[i].points = 2;
			ships_arr[i].points_to_death = 2;
		}
		else
		{
			ships_arr[i].ship_image[0] = single;
			ships_arr[i].points = 1;
			ships_arr[i].points_to_death = 1;
		}
	}
}
/*******************************************************************************************************************************************/

//Draw Ships on Subfield

/*******************************************************************************************************************************************/
void Ships_of_subfield(Ships ships_arr[field_size], which_field player, subfield SubfieldShips[ships_count][4], bool init)
{
	int indentX;
	int indentY;

	if (player == USER)
	{
		indentX = subfield1_x_indent;
		indentY = subfield1_y_indent;
	}
	else
	{
		indentX = subfield2_x_indent;
		indentY = subfield2_y_indent;
	}


	for (int i = 0; i < ships_count; i++)
	{
		for (int j = 0; j < ships_arr[i].points; j++)
		{
			ships_arr[i].is_drawed == ON_SUBFIELD ? al_draw_bitmap(ships_arr[i].ship_image[j], indentX + j * img_pix_size, indentY, 0) : 0;
			ships_arr[i].points_to_death == 0 ? al_draw_bitmap(x_img, indentX + j * img_pix_size, indentY, 0) : 0;
			init ? (SubfieldShips[i][j].x = indentX + j * img_pix_size, SubfieldShips[i][j].y = indentY) : 0;
		}
		if (i == 1)
		{
			indentY += img_pix_size * 2;
			player == USER ? indentX = subfield1_x_indent : indentX = subfield2_x_indent;
		}

		else if (i == 4)
		{
			indentY += img_pix_size * 2;
			player == USER ? indentX = subfield1_x_indent : indentX = subfield2_x_indent;
		}

		else
			indentX += img_pix_size * ships_arr[i].points + img_pix_size;
	}
}
/*******************************************************************************************************************************************/

//Select Ship on Subfield

/*******************************************************************************************************************************************/


void Selected_Ship(Ships ships_arr[field_size], int x, int y, int &ship_number, subfield SubfieldShips[ships_count][4])
{
	bool is_selected = false;

	if (ship_number != -1 && ships_arr[ship_number].is_drawed == SELECTED && x >= subfield1_x_indent && x <= subfield1_x_indent + (field_size * img_pix_size) && y >= subfield1_y_indent && y <= subfield1_y_indent + (field_size * img_pix_size))
	{
		ships_arr[ship_number].is_drawed = ON_SUBFIELD;
		ship_number = -1;
	}
	else if (ship_number == -1)
	{
		for (int i = 0; i < 10 && !is_selected; i++)
		{
			for (int j = 0; !is_selected && j < ships_arr[i].points; j++)
			{
				if (x >= SubfieldShips[i][j].x && x <= SubfieldShips[i][j].x + img_pix_size && y >= SubfieldShips[i][j].y && y <= SubfieldShips[i][j].y + img_pix_size)
				{
					if (ships_arr[i].is_drawed == ON_SUBFIELD)
					{
						ships_arr[i].is_drawed = SELECTED;
						is_selected = true;
						ship_number = i;
					}
				}
			}
		}
	}
}
/*******************************************************************************************************************************************/

//Draw Shoots

/*******************************************************************************************************************************************/

void DrawShoots(Ships ships_arr[ships_count], Fields bat_field[field_size][field_size], int x, int y, which_field field, int destroyed[2])
{
	bool is_cursos_on_field = false;
	int indent_x, indent_y;
	int temp_x, temp_y;

	//Write enemy's or user's field indent
	field == USER ? (indent_x = field1_x_indent, indent_y = field1_y_indent) : (indent_x = field2_x_indent, indent_y = field2_y_indent);

	if (field == ENEMY)
	{
		if (x >= indent_x && y >= indent_y && x <= indent_x + field_size * img_pix_size && y <= indent_y + field_size * img_pix_size)
		{
			is_cursos_on_field = true;
			temp_x = (x - indent_x) / img_pix_size;
			temp_y = (y - indent_y) / img_pix_size;
		}

	}
	else if (field == USER)
	{
		if (x >= 0 && x < field_size && y >= 0 && y < field_size)
		{
			is_cursos_on_field = true;
			temp_x = x;
			temp_y = y;
		}
	}


	//Convert mouse coordinates to field cell coordinates
	if (is_cursos_on_field)
	{
		int ship_number = bat_field[temp_y][temp_x].ship;



		if (ship_number == -1)
		{
			bat_field[temp_y][temp_x].ship = 10;
			field == USER ? damaged = false : 0;
			field == ENEMY ? enemy_shoot = true : 0;
		}
		else if (ship_number >= 0 && ship_number < ships_count && !bat_field[temp_y][temp_x].state)
		{

			ships_arr[ship_number].points_to_death > 0 ? ships_arr[ship_number].points_to_death-- : 0;
			bat_field[temp_y][temp_x].state = true;
			field == USER ? (damaged = true, destroyed[0]++) : 0;
			field == ENEMY ? (enemy_shoot = true, destroyed[1]++) : 0;

		}
		else
		{
			field == USER ? damaged = false : 0;
			field == ENEMY ? enemy_shoot = false : 0;
		}
			
		if (ships_arr[ship_number].points_to_death == 0 && ship_number >= 0 && ship_number < ships_count)
		{
			for (int i = 0; i < ships_count; i++)
			{
				for (int j = 0; j < ships_count; j++)
				{
					if (bat_field[i][j].ship == ship_number)
					{
						if (i > 0)
						{
							bat_field[i - 1][j].ship == -1 ? bat_field[i - 1][j].ship = 10 : 0;
							j > 0 && bat_field[i - 1][j - 1].ship == -1 ? bat_field[i - 1][j - 1].ship = 10 : 0;
							j < field_size - 1 && bat_field[i - 1][j + 1].ship == -1 ? bat_field[i - 1][j + 1].ship = 10 : 0;
						}
						if (i < field_size - 1)
						{
							bat_field[i + 1][j].ship == -1 ? bat_field[i + 1][j].ship = 10 : 0;
							j > 0 && bat_field[i + 1][j - 1].ship == -1 ? bat_field[i + 1][j - 1].ship = 10 : 0;
							j < field_size - 1 && bat_field[i + 1][j + 1].ship == -1 ? bat_field[i + 1][j + 1].ship = 10 : 0;
						}
						j > 0 && bat_field[i][j - 1].ship == -1 ? bat_field[i][j - 1].ship = 10 : 0;
						j < field_size - 1 && bat_field[i][j + 1].ship == -1 ? bat_field[i][j + 1].ship = 10 : 0;
					}
				}
			}
		}
	}
}
/*******************************************************************************************************************************************/

//Enemy Shoots

/*******************************************************************************************************************************************/

void EnemyShoots(Ships ships_arr[ships_count], Fields bat_field[field_size][field_size], shoots shooting[5], enemy_shoot_settings &Settings, int destroyed[2])
{
	int shootX = -2, shootY = -2;
	ships_arr[Settings.ship].points_to_death == 0 ? (Settings.shooted = false, Settings.count = 0) : 0;
	if (Settings.mode == EASY || !Settings.shooted && !damaged || ships_arr[Settings.ship].points_to_death == 0)
	{

		do
		{
			shootX = rand() % ships_count;
			shootY = rand() % ships_count;
		} while (bat_field[shootX][shootY].ship != -1 && bat_field[shootX][shootY].ship == 10 || bat_field[shootX][shootY].state);
		Settings.ship = bat_field[shootX][shootY].ship;
		Settings.first_x = shootX;
		Settings.first_y = shootY;
	}
	else if (Settings.mode == HARD && ships_arr[Settings.ship].points == 1)
	{
		Settings.shooted = false;
	}
	else if (Settings.mode == HARD)
	{
		if (Settings.ship >= 0 && !Settings.shooted)
		{

			shootX = Settings.first_x;
			shootY = Settings.first_y;
			if (shootX > 0 && bat_field[shootX - 1][shootY].ship != 10)
			{
				if (!bat_field[shootX - 1][shootY].state)
				{
					shooting[Settings.count].x = shootX - 1;
					shooting[Settings.count].y = shootY;
					shooting[Settings.count].state = X_DOWN;
					Settings.count++;
				}
			}
			if (shootX < field_size - 1 && bat_field[shootX + 1][shootY].ship != 10)
			{
				if (!bat_field[shootX + 1][shootY].state)
				{
					shooting[Settings.count].x = shootX + 1;
					shooting[Settings.count].y = shootY;
					shooting[Settings.count].state = X_UP;
					Settings.count++;
				}

			}
			if (shootY > 0 && bat_field[shootX][shootY - 1].ship != 10)
			{
				if (!bat_field[shootX][shootY - 1].state)
				{
					shooting[Settings.count].x = shootX;
					shooting[Settings.count].y = shootY - 1;
					shooting[Settings.count].state = Y_DOWN;
					Settings.count++;
				}

			}
			if (shootY < field_size - 1 && bat_field[shootX][shootY + 1].ship != 10)
			{
				if (!bat_field[shootX][shootY + 1].state)
				{
					shooting[Settings.count].x = shootX;
					shooting[Settings.count].y = shootY + 1;
					shooting[Settings.count].state = Y_UP;
					Settings.count++;
				}
			}
			shoots temp;
			for (int i = 0; i < 10 && Settings.count > 0; i++)
			{
				Settings.random = rand() % Settings.count;
				temp = shooting[Settings.count - 1];
				shooting[Settings.count - 1] = shooting[Settings.random];
				shooting[Settings.random] = temp;
			}
			Settings.shooted = true;
		}
		if (ships_arr[Settings.ship].points - ships_arr[Settings.ship].points_to_death == 1)
		{
			shootX = shooting[--Settings.count].x;
			shootY = shooting[Settings.count].y;
		}
		else
		{
			int x = shooting[Settings.count].x;
			int y = shooting[Settings.count].y;

			if (shooting[Settings.count].state == X_UP && damaged && x + 1 < field_size  && bat_field[x + 1][y].ship != 10)
				x++;
			else if (shooting[Settings.count].state == X_UP)
			{
				shooting[Settings.count].state = X_DOWN;
				x = Settings.first_x;
				y = Settings.first_y;
				x--;
			}

			else if (shooting[Settings.count].state == X_DOWN && damaged && x > 0 && bat_field[x - 1][y].ship != 10)
				x--;
			else if (shooting[Settings.count].state == X_DOWN)
			{
				shooting[Settings.count].state = X_UP;
				x = Settings.first_x;
				y = Settings.first_y;
				x++;
			}

			else if (shooting[Settings.count].state == Y_UP && damaged && y + 1 < field_size && bat_field[x][y+1].ship != 10)
				y++;
			else if (shooting[Settings.count].state == Y_UP)
			{
				shooting[Settings.count].state = Y_DOWN;
				x = Settings.first_x;
				y = Settings.first_y;
				y--;
			}

			else if (shooting[Settings.count].state == Y_DOWN && damaged && y > 0 && bat_field[x][y - 1].ship != 10)
				y--;
			else if (shooting[Settings.count].state == Y_DOWN)
			{
				shooting[Settings.count].state = Y_UP;
				x = Settings.first_x;
				y = Settings.first_y;
				y++;
			}

			shootX = x;
			shootY = y;

			shooting[Settings.count].x = x;
			shooting[Settings.count].y = y;
		}
	}
	shooting[4].x = shootX;
	shooting[4].y = shootY;
	DrawShoots(ships_arr, bat_field, shootY, shootX, USER, destroyed);
}



