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

image_position position = HORIZONTAL;

const int field_size = 10;


int ship_number = 0;
int curr_ship = -1;
int image = 0;
int field1_x_indent = 40;
int field1_y_indent = 40;
bool is_place_empty = true;

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





Ships field[10];

int bat_field[field_size][field_size] = { -1 };



void DrawCursor(int x, int y)
{





	for (int i = ship_number; i < ship_number + 1; i++)
	{
		if (i == 0)
		{
			if (position == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[1], 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[2], 0, 0, x + 40, y + 80, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[3], 0, 0, x + 40, y + 120, 1.566, 0);
			}
			else
			{

				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[1], x + 40, y, 0);
				al_draw_bitmap(field[i].ship_image[2], x + 80, y, 0);
				al_draw_bitmap(field[i].ship_image[3], x + 120, y, 0);
			}
		}
		else if (i == 1 || i == 2)
		{
			if (position == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[1], 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[2], 0, 0, x + 40, y + 80, 1.566, 0);
			}
			else
			{
				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[1], x + 40, y, 0);
				al_draw_bitmap(field[i].ship_image[2], x + 80, y, 0);
			}
		}
		else if (i > 2 && i < 6)
		{
			if (position == VERTICAL)
			{

				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[1], 0, 0, x + 40, y + 40, 1.566, 0);
			}
			else
			{

				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[1], x + 40, y, 0);
			}
		}
		else if (i < 10)
		{
			al_draw_bitmap(field[i].ship_image[0], x, y, 0);
		}
	}
}

void main()
{

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
	display = al_create_display(1200, 600);
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
			field[i].ship_image[j] = nullptr;
		}
		if (i == 0)
		{
			field[i].ship_image[0] = back;
			field[i].ship_image[1] = middle1;
			field[i].ship_image[2] = middle2;
			field[i].ship_image[3] = front;
			field[i].points_to_death = 4;
		}
		else if (i == 1 || i == 2)
		{
			field[i].ship_image[0] = back;
			field[i].ship_image[1] = middle2;
			field[i].ship_image[2] = front;
			field[i].points_to_death = 3;
		}
		else if (i > 2 && i < 6)
		{
			field[i].ship_image[0] = back;
			field[i].ship_image[1] = front;
			field[i].points_to_death = 2;
		}
		else
		{
			field[i].ship_image[0] = single;
			field[i].points_to_death = 1;
		}
	}


	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());


	while (true)
	{
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 40, 40, 0);
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = event.mouse.x;
			y = event.mouse.y;
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
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1 && ship_number < 10)
			{
				// Convertaion mouse x and y positions to field cell
				temp_x = (x - field1_x_indent - (x % 40)) / 40;
				temp_y = (y - field1_x_indent - (y % 40)) / 40;

				field[ship_number].ship_pos = position;
				is_place_empty = true;
				int count = field[ship_number].points_to_death;
				if (position == VERTICAL)
				{
					for (int i = 0; i < count; i++)
					{
						if (temp_y + i >= 0 && temp_y + i < field_size && temp_x >= 0 && temp_x < field_size && bat_field[temp_y + i][temp_x] == -1)
						{
							if (temp_y > 0 && bat_field[temp_y - 1][temp_x] == -1 && temp_y + count < field_size && bat_field[temp_y + count][temp_x] == -1)
								0;
						}
						else
							is_place_empty = false;
					}
					for (int i = 0; i < field[ship_number].points_to_death && is_place_empty; i++)
					{
						bat_field[temp_y + i][temp_x] = ship_number;
					}
					is_place_empty ? ship_number++ : 0;
				}
				else if (position == HORIZONTAL)
				{
					for (int i = 0; i < field[ship_number].points_to_death; i++)
					{
						if (temp_y >= 0 && temp_y < field_size && temp_x + i >= 0 && temp_x + i < field_size && bat_field[temp_y][temp_x + i] == -1)
							0;
						else
							is_place_empty = false;
					}
					for (int i = 0; i < field[ship_number].points_to_death && is_place_empty; i++)
					{
						bat_field[temp_y][temp_x + i] = ship_number;
					}
					is_place_empty ? ship_number++ : 0;
				}
			}
		}

		//Drawing 
		//DrawShips();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				curr_ship = bat_field[i][j];
				if (curr_ship >= 0)
				{
					if (field[curr_ship].ship_pos == HORIZONTAL)
					{
						al_draw_bitmap(field[curr_ship].ship_image[field[curr_ship].img_number], j * 40 + field1_x_indent, i * 40 + field1_x_indent, 0);
					}
					else
					{
						al_draw_rotated_bitmap(field[curr_ship].ship_image[field[curr_ship].img_number], 0, 0, j * 40 + field1_x_indent + 40, i * 40 + field1_x_indent, 1.566, 0);
					}
					field[curr_ship].img_number++;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			field[i].img_number = 0;
		}
		DrawCursor(x, y);
	}
}