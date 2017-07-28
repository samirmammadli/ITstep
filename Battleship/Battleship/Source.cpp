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
	int img_number = 0;
	ALLEGRO_BITMAP** ship_image = new ALLEGRO_BITMAP*[4];
	image_position	ship_pos = HORIZONTAL;
};



MyStruct field[10];

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
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 80, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 120, 1.566, 0);
			}
			else
			{
				
				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 40, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 80, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 120, y, 0);
			}
		}
		else if (i == 1 || i == 2)
		{
			if (position == VERTICAL)
			{
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 40, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 80, 1.566, 0);
			}
			else
			{
				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 40, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 80, y, 0);
			}
		}
		else if (i > 2 && i < 6)
		{
			if (position == VERTICAL)
			{

				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y, 1.566, 0);
				al_draw_rotated_bitmap(field[i].ship_image[0], 0, 0, x + 40, y + 40, 1.566, 0);
			}
			else
			{

				al_draw_bitmap(field[i].ship_image[0], x, y, 0);
				al_draw_bitmap(field[i].ship_image[0], x + 40, y, 0);
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
	int x, y;

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
		}
		else if (i == 1 || i == 2)
		{
			field[i].ship_image[0] = back;
			field[i].ship_image[1] = middle2;
			field[i].ship_image[2] = front;
		}
		else if (i > 2 && i < 6)
		{
			field[i].ship_image[0] = back;
			field[i].ship_image[1] = front;
		}
		else
			field[i].ship_image[0] = single;
	}



	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());


	while (true)
	{
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, 0);
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
				temp_x = x - (x % 40);
				temp_y = y - (y % 40);
				field[ship_number].ship_pos = position;
				if (x < 400 && y < 400 )
				{
					if (true)
					{
						if (ship_number == 0)
						{

							for (int i = 0; i < 4; i++)
							{
							if (position == VERTICAL)
							bat_field[temp_y / 40 + i][temp_x / 40 ] = ship_number;
							else
							bat_field[temp_y / 40][temp_x / 40 + i] = ship_number;
							}
						}
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

		//Drawing 
		//DrawShips();
		DrawCursor(x, y);


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (bat_field[i][j] == 0)
				{
					if (field[bat_field[i][j]].ship_pos == VERTICAL)
					{
						al_draw_rotated_bitmap(field[0].ship_image[field[0].img_number++], 0, 0, j * 40 + 40, i * 40, 1.566, 0);
					}
					else
					{
						al_draw_bitmap(field[0].ship_image[field[0].img_number++], j * 40, i * 40, 0);
					
					}
				}
			}
		}

		field[0].img_number = 0;
	}
}