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

//ALLEGRO_BITMAP* back = al_load_bitmap("back.jpg");
//ALLEGRO_BITMAP* middle1 = al_load_bitmap("2.jpg");
//ALLEGRO_BITMAP* middle2 = al_load_bitmap("3.jpg");
//ALLEGRO_BITMAP* front = al_load_bitmap("front.jpg");


struct MyStruct
{
	int x1 = -20;
	int y1 = -20;
	int image = 0;
};

MyStruct field[400];


void main()
{
	srand(time(0));

	//Data section
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_BITMAP* player = nullptr;
	ALLEGRO_BITMAP* background = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_BITMAP* back = nullptr;
	ALLEGRO_BITMAP* middle1 = nullptr;
	ALLEGRO_BITMAP* middle2 = nullptr;
	ALLEGRO_BITMAP* front = nullptr;
	ALLEGRO_EVENT event;
	////////////
	

	//Init section
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();

	//Settings
	display = al_create_display(1200, 600);
	background = al_load_bitmap("background1.jpg");
	player = al_load_bitmap("back.jpg");
	back = al_load_bitmap("back.jpg");
	middle1 = al_load_bitmap("2.jpg");
	middle2 = al_load_bitmap("3.jpg");
	front = al_load_bitmap("front.jpg");
	


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
					field[bit_count].y1 = y- (y % 40);
					field[bit_count].image = image;
					bit_count++;
				}

			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
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
			if (field[i].image == 0)
			{
				al_draw_bitmap(back, field[i].x1, field[i].y1, 0);
			}
			else if (field[i].image == 1)
			{
				al_draw_bitmap(middle1, field[i].x1, field[i].y1, 0);
			}
			else if (field[i].image == 2)
			{
				al_draw_bitmap(middle2, field[i].x1, field[i].y1, 0);
			}
			else if (field[i].image == 3)
			{
				al_draw_bitmap(front, field[i].x1, field[i].y1, 0);
			}
			
		}
		

		if (image == 0)
		{
			al_draw_bitmap(back, x, y, 0);
		}
		else if (image == 1)
		{
			al_draw_bitmap(middle1, x, y, 0);
		}
		else if (image == 2)
		{
			al_draw_bitmap(middle2, x, y, 0);
		}
		else if (image == 3)
		{
			al_draw_bitmap(front, x, y, 0);
		}

		
	}




	//al_wait_for_event(event_queue, &event);


}