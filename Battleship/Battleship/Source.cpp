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

const int row = 25;
const int col = 25;


int ship_number = 0;
int image = 0;

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



struct MyStruct
{
	int ship_x = -20;
	int ship_y = -20;
	int image = 0;
	ALLEGRO_BITMAP* ship_back = nullptr;
	ALLEGRO_BITMAP* ship_middle1 = nullptr;
	ALLEGRO_BITMAP* ship_middle2 = nullptr;
	ALLEGRO_BITMAP* ship_front = nullptr;
	ALLEGRO_BITMAP* ship_single = nullptr;
	image_position	ship_pos = HORIZONTAL;
};



MyStruct field[10];

int bat_field[10][10] = { -1 };


void DrawShips(int x = -1, int y = -1)
{

	for (int i = 0; i < ship_number; i++)
	{
		x = field[i].ship_x, y = field[i].ship_y;
		if (i == 0)
		{
			if (field[i].ship_pos == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle1, 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle2, 0, 0, x + 40, y + 80, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 120, 1.566, 0);
			}
			else
			{
				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_middle1, x + 40, y, 0);
				al_draw_bitmap(field[i].ship_middle2, x + 80, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 120, y, 0);
			}
		}
		else if (i == 1 || i == 2)
		{
			if (field[i].ship_pos == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle1, 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 80, 1.566, 0);
			}
			else
			{
				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_middle1, x + 40, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 80, y, 0);
			}
		}
		else if (i > 2 && i < 6)
		{
			if (field[i].ship_pos == VERTICAL)
			{

				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 40, 1.566, 0);
			}
			else
			{

				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 40, y, 0);
			}
		}
		else if (i < 10)
		{
			al_draw_bitmap(field[i].ship_single, x, y, 0);
		}
	}
}


void DrawCursor(int x, int y)
{

	for (int i = ship_number; i < ship_number + 1; i++)
	{
		if (i == 0)
		{
			if (position == VERTICAL)
			{
				
				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle1, 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle2, 0, 0, x + 40, y + 80, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 120, 1.566, 0);
			}
			else
			{
				
				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_middle1, x + 40, y, 0);
				al_draw_bitmap(field[i].ship_middle2, x + 80, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 120, y, 0);
			}
		}
		else if (i == 1 || i == 2)
		{
			if (position == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_middle1, 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 80, 1.566, 0);
			}
			else
			{
				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_middle1, x + 40, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 80, y, 0);
			}
		}
		else if (i > 2 && i < 6)
		{
			if (position == VERTICAL)
			{

				al_draw_rotated_bitmap(field[i].ship_back, 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_front, 0, 0, x + 40, y + 40, 1.566, 0);
			}
			else
			{

				al_draw_bitmap(field[i].ship_back, x, y, 0);
				al_draw_bitmap(field[i].ship_front, x + 40, y, 0);
			}
		}
		else if (i < 10)
		{
			al_draw_bitmap(field[i].ship_single, x, y, 0);
		}
	}
}

void main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bat_field[i][j] = -1;
		}
	}
	int x;
	int y;
	int temp_x = 0;
	int temp_y = 0;
	////////////


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
		field[i].ship_back = back;
		field[i].ship_middle1 = middle1;
		field[i].ship_middle2 = middle2;
		field[i].ship_front = front;
		field[i].ship_single = single;
	}



	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	while (true)
	{
		al_wait_for_event(event_queue, &event);
		x = event.mouse.x;
		y = event.mouse.y;

		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1)
			{
				if (x < 400 && y < 400 && ship_number < 10)
				{
					temp_x = x - (x % 40);
					temp_y = y - (y % 40);

					field[ship_number].ship_x = temp_x;
					field[ship_number].ship_y = temp_y;
					field[ship_number].ship_pos = position;

					for (int i = 0; i < 4; i++)
					{
						bat_field[temp_y / 40 + i][temp_x / 40] = ship_number;
					}
					ship_number++;

				}

			}
			cout << temp_x << "   " << temp_y << "\n\n";
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					cout << bat_field[i][j] << "    ";
				}
				cout << "\n";
			}

			cout << "\n\n\n";
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
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, 0);

		//Drawing 
		DrawShips();
		DrawCursor(x, y);
		
	}
}