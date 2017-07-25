#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;



const int row = 25;
const int col = 25;



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

	//Settings
	display = al_create_display(1200, 600);
	background = al_load_bitmap("background.jpg");
	player = al_load_bitmap("1.jpg");
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	
	al_draw_bitmap(background, 0, 0, 0);
	//al_clear_to_color(al_map_rgb(0, 204, 102));
	al_flip_display();
	al_draw_bitmap(player, 41, 121, 0);
	al_flip_display();

	al_wait_for_event(event_queue, &event);
	if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		exit(0);

}