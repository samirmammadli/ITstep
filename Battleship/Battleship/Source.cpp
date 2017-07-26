#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;



const int row = 25;
const int col = 25;


int x;
int y;
int bit_count = 0;
int image = 0;


struct MyStruct
{
	int x1 = -20;
	int y1 = - 20;
	int image1 = 0;
};

MyStruct field[1000];

void main()
{
	srand(time(0));

	//Data section
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_BITMAP* empty = nullptr;
	ALLEGRO_BITMAP* wall = nullptr;
	ALLEGRO_BITMAP* food = nullptr;
	ALLEGRO_BITMAP* player = nullptr;
	ALLEGRO_BITMAP* background = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_EVENT event;

	//Init section
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();

	//Settings
	display = al_create_display(1200, 600);
	background = al_load_bitmap("background1.jpg");
	player = al_load_bitmap("back.jpg");
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
					if (x < 400 && y < 400)
					{
						field[bit_count].x1 = x - (x % 40);
						field[bit_count].y1 = y - (y % 40);
						field[bit_count].image1 = image;
						bit_count++;
					}
				}
			}
			if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
				exit(0);
				}
				else if (event.keyboard.keycode == ALLEGRO_KEY_W)
				{
					
					if (image == 3)
					{
						image = 0;
					}
					else
						image++;
				}
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(background, 0, 0, 0);
			//al_draw_bitmap(player, 41, 121, 0);
			
			
			for (int i = 0; i < bit_count; i++)
			{
				if (field[i].image1 == 0)
				{
					player = al_load_bitmap("back.jpg");
				}
				else if (field[i].image1 == 1)
				{
					player = al_load_bitmap("2.jpg");
				}
				else if (field[i].image1 == 2)
				{
					player = al_load_bitmap("3.jpg");
				}
				else if (field[i].image1 == 3)
				{
					player = al_load_bitmap("front.jpg");
				}
				al_draw_bitmap(player, field[i].x1, field[i].y1, 0);
			}

			if (image == 0)
			{
				player = al_load_bitmap("back.jpg");
			}
			else if (image == 1)
			{
				player = al_load_bitmap("2.jpg");
			}
			else if (image == 2)
			{
				player = al_load_bitmap("3.jpg");
			}
			else if (image == 3)
			{
				player = al_load_bitmap("front.jpg");
			}

			al_draw_bitmap(player, x, y, 0);	
	}
	
	
	

	//al_wait_for_event(event_queue, &event);
	

}