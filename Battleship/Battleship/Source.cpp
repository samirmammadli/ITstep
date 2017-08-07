#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;

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

int drawed_ships = 0;
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
ALLEGRO_BITMAP* ocean = nullptr;
ALLEGRO_BITMAP* back = nullptr;
ALLEGRO_BITMAP* middle1 = nullptr;
ALLEGRO_BITMAP* middle2 = nullptr;
ALLEGRO_BITMAP* front = nullptr;
ALLEGRO_BITMAP* single = nullptr;
ALLEGRO_BITMAP* player = nullptr;
ALLEGRO_BITMAP* background = nullptr;
ALLEGRO_BITMAP* ships_field_image = nullptr;
ALLEGRO_BITMAP* red_a = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_EVENT event;


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
	int points_to_death = 0;
	int img_number = 0;
	ALLEGRO_BITMAP** ship_image = new ALLEGRO_BITMAP*[4]{nullptr};
	Ship_State is_drawed = ON_SUBFIELD;
	image_position	ship_pos = HORIZONTAL;
};


void init_ships_params(Ships ships_arr[ships_count], ALLEGRO_BITMAP* back, ALLEGRO_BITMAP* middle1, ALLEGRO_BITMAP* middle2, ALLEGRO_BITMAP* front);
bool sort_ships(Ships field[ships_count], int x, int y, int &ship_number, arrangement, Fields bat_field[field_size][field_size], which_field player);
void DrawSelectedShip(Ships field[ships_count], int x, int y, int ship_number, Fields bat_field[field_size][field_size]);
void Draw_ships_on_field(Fields bat_field[field_size][field_size], Ships ships_arr[ships_count], which_field player);
void Ships_of_subfield(Ships ships_arr[field_size], which_field player, subfield SubfieldShips[ships_count][4], bool init = false);
void Selected_Ship(Ships ships_arr[field_size], int x, int y, int &ship_number, subfield SubfieldShips[ships_count][4]);



void main()
{

	
	int ship_number = 0;
	int image = 0;

	Ships *ships_arr_user = new Ships[ships_count];
	Ships *ships_arr_enemy = new Ships[ships_count];

	Fields bat_field_user[field_size][field_size];
	Fields bat_field_enemy[field_size][field_size];

	subfield SubfieldShips[ships_count][4];
	srand(time(0));



	// Current Mouse x and y positions
	int x = 0, y = 0;

	// Convertaion mouse x and y positions to field cell
	int temp_x = 0;
	int temp_y = 0;


	//Init section
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();


	//Settings
	display = al_create_display(1150, 700);
	al_set_window_title(display, "Sea Battle");
	background = al_load_bitmap("fon.png");
	ships_field_image = al_load_bitmap("background2.png");
	ocean = al_load_bitmap("ocean.jpg");
	player = al_load_bitmap("1.png");
	back = al_load_bitmap("back.jpg");
	middle1 = al_load_bitmap("2.jpg");
	middle2 = al_load_bitmap("3.jpg");
	front = al_load_bitmap("front.jpg");
	single = al_load_bitmap("one.jpg");
	red_a = al_load_bitmap("2.png");


	init_ships_params(ships_arr_user, back, middle1, middle2, front);
	init_ships_params(ships_arr_enemy, back, middle1, middle2, front);


	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	sort_ships(ships_arr_enemy, x, y, ship_number, RANDOM, bat_field_enemy, ENEMY);
	Ships_of_subfield(ships_arr_user, USER, SubfieldShips, true);
	ship_number = -1;


	while (drawed_ships != 10)
	{
		
		al_clear_to_color(al_map_rgb(15, 74, 88));
		al_draw_bitmap(ocean, 0, 0, 0);
		al_draw_bitmap(background, field1_x_indent, field1_y_indent, 0);
		al_draw_bitmap(ships_field_image, subfield1_x_indent, subfield1_y_indent, 0);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		Draw_ships_on_field(bat_field_user, ships_arr_user, USER);
		DrawSelectedShip(ships_arr_user, x, y, ship_number, bat_field_user);
		al_flip_display();
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = event.mouse.x;
			y = event.mouse.y;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(0);
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);
			else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
				sort_ships(ships_arr_user, x, y, ship_number, RANDOM, bat_field_user, USER);
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1)
			{
				Selected_Ship(ships_arr_user, x, y, ship_number, SubfieldShips);
				ship_number > -1 ? sort_ships(ships_arr_user, x, y, ship_number, MANUAL, bat_field_user, USER) : 0;
			}

			else if (event.mouse.button == 2 && ship_number >= 0 && ship_number < 10)
				ships_arr_user[ship_number].ship_pos == HORIZONTAL ? ships_arr_user[ship_number].ship_pos = VERTICAL : ships_arr_user[ship_number].ship_pos = HORIZONTAL;
		}
		cout << drawed_ships << endl;
	}

	for (int i = 0; i < ships_count; i++)
	{
		ships_arr_user[i].is_drawed = ON_SUBFIELD;
	}


	while (true)
	{
		al_flip_display();
		al_clear_to_color(al_map_rgb(15, 74, 88));
		al_draw_bitmap(ocean, 0, 0, 0);
		al_draw_bitmap(background, field1_x_indent, field1_y_indent, 0);
		al_draw_bitmap(background, field2_x_indent, field2_y_indent, 0);
		al_draw_bitmap(ships_field_image, subfield1_x_indent, subfield1_y_indent, 0);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = event.mouse.x;
			y = event.mouse.y;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(0);
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1)
			{
				0;
			}
				
			else if (event.mouse.button == 2 && ship_number >= 0 && ship_number < 10)
				ships_arr_user[ship_number].ship_pos == HORIZONTAL ? ships_arr_user[ship_number].ship_pos = VERTICAL : ships_arr_user[ship_number].ship_pos = HORIZONTAL;
		}

		//Drawing 
		Draw_ships_on_field(bat_field_user, ships_arr_user, USER);
		Draw_ships_on_field(bat_field_enemy, ships_arr_enemy, ENEMY);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		Ships_of_subfield(ships_arr_enemy, ENEMY, SubfieldShips);
	
		DrawSelectedShip(ships_arr_user, x, y, ship_number, bat_field_user);
	}
}

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
	int count = ships_arr[ship_number].points_to_death;
	int temp_x;
	int temp_y;

	//Write enemy's or user's field indent
	player == USER ? (indent_x = field1_x_indent, indent_y = field1_y_indent) : (indent_x = field2_x_indent, indent_y = field2_y_indent);
	//Convert mouse coordinates to field cell coordinates
	if (x >= indent_x && y >= indent_y)
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
			count = ships_arr[ship_number].points_to_death;
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
			for (int i = 0; i < ships_arr[ship_number].points_to_death && is_place_empty && Case != CHECK; i++)
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
	for (int i = 0; i < ships_arr[ship_number].points_to_death; i++)
	{
		if (ships_arr[ship_number].ship_pos == VERTICAL)
		{
			al_draw_rotated_bitmap(ships_arr[ship_number].ship_image[i], 0, 0, x + img_pix_size, y + i * img_pix_size, 1.566, 0);
			correct_position ? al_draw_bitmap(player, x, y + i * img_pix_size, 0) : al_draw_bitmap(red_a, x, y + i * img_pix_size, 0);
		}

		else
		{
			al_draw_bitmap(ships_arr[ship_number].ship_image[i], x + i * img_pix_size, y, 0);
			correct_position ? al_draw_bitmap(player, x + i * img_pix_size, y, 0) : al_draw_bitmap(red_a, x + i * img_pix_size, y, 0);
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
			if (curr_ship >= 0)
			{
				int u = ships_arr[curr_ship].img_number;
				if (ships_arr[curr_ship].ship_pos == HORIZONTAL)
				{
					al_draw_bitmap(ships_arr[curr_ship].ship_image[u], j * img_pix_size + indent_x, i * img_pix_size + indent_y, 0);
				}
				else
				{
					al_draw_rotated_bitmap(ships_arr[curr_ship].ship_image[u], 0, 0, j * img_pix_size + indent_x + img_pix_size, i * img_pix_size + indent_y, 1.566, 0);
				}
				ships_arr[curr_ship].img_number++;
			}
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
			ships_arr[i].points_to_death = 4;
		}
		else if (i == 1 || i == 2)
		{
			ships_arr[i].ship_image[0] = back;
			ships_arr[i].ship_image[1] = middle2;
			ships_arr[i].ship_image[2] = front;
			ships_arr[i].points_to_death = 3;
		}
		else if (i > 2 && i < 6)
		{
			ships_arr[i].ship_image[0] = back;
			ships_arr[i].ship_image[1] = front;
			ships_arr[i].points_to_death = 2;
		}
		else
		{
			ships_arr[i].ship_image[0] = single;
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
		for (int j = 0; j < ships_arr[i].points_to_death; j++)
		{
			ships_arr[i].is_drawed == ON_SUBFIELD ? al_draw_bitmap(ships_arr[i].ship_image[j], indentX + j * img_pix_size, indentY, 0) : 0;
			init ? (SubfieldShips[i][j].x = indentX + j * img_pix_size , SubfieldShips[i][j].y = indentY) : 0;	
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
			indentX += img_pix_size * ships_arr[i].points_to_death + img_pix_size;
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
			for (int j = 0; !is_selected && j < ships_arr[i].points_to_death; j++)
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