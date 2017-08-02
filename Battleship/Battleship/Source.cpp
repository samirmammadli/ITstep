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



const int field_size = 10;
const int ships_count = 10;
const int field1_x_indent = 50;
const int field1_y_indent = 70;
const int field2_x_indent = 700;
const int field2_y_indent = 80;




//Data section
ALLEGRO_DISPLAY* display = nullptr;
ALLEGRO_BITMAP* player = nullptr;
ALLEGRO_BITMAP* background = nullptr;
ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
ALLEGRO_BITMAP* back = nullptr;
ALLEGRO_BITMAP* middle1 = nullptr;
ALLEGRO_BITMAP* middle2 = nullptr;
ALLEGRO_BITMAP* front = nullptr;
ALLEGRO_BITMAP* single = nullptr;
ALLEGRO_BITMAP* red_a = nullptr;
ALLEGRO_EVENT event;


struct Ships
{
	int points_to_death = 0;
	int img_number = 0;
	ALLEGRO_BITMAP** ship_image = new ALLEGRO_BITMAP*[4];
	image_position	ship_pos = HORIZONTAL;
};


bool check_position(Ships field[ships_count], int x, int y, int &ship_number, image_position position, arrangement, int bat_field[field_size][field_size]);
void DrawSelectedShip(Ships field[ships_count], int x, int y, int ship_number, image_position position, int bat_field[field_size][field_size]);


void main()
{
	int ship_number = 0;
	int curr_ship = -1;
	int image = 0;
	image_position position = HORIZONTAL;


	Ships ships_arr[10];

	int bat_field[field_size][field_size] = { -1 };

	srand(time(0));
	for (int i = 0; i < field_size; i++)
	{
		for (int j = 0; j < field_size; j++)
		{
			bat_field[i][j] = -1;
		}
	}


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
	display = al_create_display(1200, 700);
	al_set_window_title(display, "Sea Battle");
	background = al_load_bitmap("background1.jpg");
	player = al_load_bitmap("1.png");
	back = al_load_bitmap("back.jpg");
	middle1 = al_load_bitmap("2.jpg");
	middle2 = al_load_bitmap("3.jpg");
	front = al_load_bitmap("front.jpg");
	single = al_load_bitmap("one.jpg");
	red_a = al_load_bitmap("2.png");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ships_arr[i].ship_image[j] = nullptr;
		}
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


	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));


	while (true)
	{
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, field1_x_indent, field1_y_indent, 0);
		al_draw_bitmap(background, field2_x_indent, field2_y_indent, 0);
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = event.mouse.x;
			y = event.mouse.y;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			exit(0);
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				exit(0);
			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_W)
			{
				position == HORIZONTAL ? position = VERTICAL : position = HORIZONTAL;
			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
			{
				check_position(ships_arr, x, y, ship_number, position, RANDOM, bat_field);
			}
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			check_position(ships_arr, x, y,ship_number, position, MANUAL, bat_field);
		}

		//Drawing 
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				curr_ship = bat_field[i][j];
				if (curr_ship >= 0)
				{
					if (ships_arr[curr_ship].ship_pos == HORIZONTAL)
					{
						al_draw_bitmap(ships_arr[curr_ship].ship_image[ships_arr[curr_ship].img_number], j * 40 + field1_x_indent, i * 40 + field1_y_indent, 0);
					}
					else
					{
						al_draw_rotated_bitmap(ships_arr[curr_ship].ship_image[ships_arr[curr_ship].img_number], 0, 0, j * 40 + field1_x_indent + 40, i * 40 + field1_y_indent, 1.566, 0);
					}
					ships_arr[curr_ship].img_number++;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			ships_arr[i].img_number = 0;
		}
		DrawSelectedShip(ships_arr, x, y, ship_number, position, bat_field);

		
	}
}
/*******************************************************************************************************************************************/


bool check_position(Ships ships_arr[ships_count], int x, int y, int &ship_number, image_position position, arrangement Case, int bat_field[field_size][field_size])
{
	static int urka = 0;


	bool is_place_empty = true;
	int steps = 1;
	int count = ships_arr[ship_number].points_to_death;
	int temp_x = (x - field1_x_indent ) / 40;
	int temp_y = (y - field1_y_indent ) / 40;
	ships_arr[ship_number].ship_pos = position;
	cout << temp_x << "          " << temp_y  << "           " << x << "     " << y<< endl;

	if (Case == RANDOM)
	{
		steps = 5000;
		ship_number = 0;
		for (int i = 0; i < field_size; i++)
		{
			for (int j = 0; j < field_size; j++)
			{
				bat_field[i][j] = -1;
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
				bat_field[temp_y - 1][temp_x] != -1 ? is_place_empty = false : 0;
				if (temp_x > 0)
					bat_field[temp_y - 1][temp_x - 1] != -1 ? is_place_empty = false : 0;
				if (temp_x < field_size - 1)
					bat_field[temp_y - 1][temp_x + 1] != -1 ? is_place_empty = false : 0;

			}
			if (temp_y + count < field_size)
			{
				bat_field[temp_y + count][temp_x] != -1 ? is_place_empty = false : 0;
				if (temp_x > 0)
					bat_field[temp_y + count][temp_x - 1] != -1 ? is_place_empty = false : 0;
				if (temp_x < field_size - 1)
					bat_field[temp_y + count][temp_x + 1] != -1 ? is_place_empty = false : 0;
			}

			for (int i = 0; i < count && is_place_empty; i++)
			{
				if (temp_y + i >= 0 && temp_y + i < field_size && temp_x >= 0 && temp_x < field_size && bat_field[temp_y + i][temp_x] == -1)
				{
					if (temp_x > 0)
						bat_field[temp_y + i][temp_x - 1] != -1 ? is_place_empty = false : 0;
					if (temp_x < field_size - 1)
						bat_field[temp_y + i][temp_x + 1] != -1 ? is_place_empty = false : 0;
				}
				else
					is_place_empty = false;
			}
			for (int i = 0; i < ships_arr[ship_number].points_to_death && is_place_empty && Case != CHECK; i++)
			{
				bat_field[temp_y + i][temp_x] = ship_number;
			}
			is_place_empty && Case != CHECK ? ship_number++ : 0;
		}
		else if (ships_arr[ship_number].ship_pos == HORIZONTAL)
		{
			if (temp_x > 0)
			{
				bat_field[temp_y][temp_x - 1] != -1 ? is_place_empty = false : 0;
				if (temp_y > 0)
					bat_field[temp_y - 1][temp_x - 1] != -1 ? is_place_empty = false : 0;
				if (temp_y < field_size - 1)
					bat_field[temp_y + 1][temp_x - 1] != -1 ? is_place_empty = false : 0;

			}
			if (temp_x + count < field_size)
			{
				bat_field[temp_y][temp_x + count] != -1 ? is_place_empty = false : 0;
				if (temp_y > 0)
					bat_field[temp_y - 1][temp_x + count] != -1 ? is_place_empty = false : 0;
				if (temp_y < field_size - 1)
					bat_field[temp_y + 1][temp_x + count] != -1 ? is_place_empty = false : 0;
			}

			for (int i = 0; i < count; i++)
			{
				if (temp_y >= 0 && temp_y < field_size && temp_x + i >= 0 && temp_x + i < field_size && bat_field[temp_y][temp_x + i] == -1)
				{
					if (temp_y > 0)
						bat_field[temp_y - 1][temp_x + i] != -1 ? is_place_empty = false : 0;
					if (temp_y < field_size - 1)
						bat_field[temp_y + 1][temp_x + i] != -1 ? is_place_empty = false : 0;
				}
				else
					is_place_empty = false;
			}
			for (int i = 0; i < count && is_place_empty && Case != CHECK; i++)
			{
				bat_field[temp_y][temp_x + i] = ship_number;
			}
			is_place_empty && Case != CHECK ? ship_number++ : 0;
		}
	}

	if (Case == CHECK)
		return is_place_empty;
}
/*******************************************************************************************************************************************/

void DrawSelectedShip(Ships ships_arr[ships_count], int x, int y, int ship_number, image_position position, int bat_field[field_size][field_size])
{
	bool correct_position = check_position(ships_arr, x, y, ship_number, position, CHECK, bat_field);
	for (int i = 0; i < ships_arr[ship_number].points_to_death; i++)
	{
		if (position == VERTICAL)
		{
			al_draw_rotated_bitmap(ships_arr[ship_number].ship_image[i], 0, 0, x + 40, y + i * 40, 1.566, 0);
			correct_position ? al_draw_bitmap(player, x, y + i * 40, 0) : al_draw_bitmap(red_a, x, y + i * 40, 0);
		}
			
		else
		{
			al_draw_bitmap(ships_arr[ship_number].ship_image[i], x + i * 40, y, 0);
			correct_position ? al_draw_bitmap(player, x + i * 40, y, 0) : al_draw_bitmap(red_a, x + i * 40, y, 0);
		}
	}
}