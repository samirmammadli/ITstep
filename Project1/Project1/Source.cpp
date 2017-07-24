#include <iostream>
#include <windows.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;


void main()
{
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP * image;
	ALLEGRO_COLOR color = al_map_rgb(0, 0, 0);

	ALLEGRO_BITMAP ***images = new ALLEGRO_BITMAP**[5];
	images[0] = new ALLEGRO_BITMAP*;
	


	al_init();
	al_init_image_addon();

	
	
	display = al_create_display(800, 600);
	al_clear_to_color(color);
	
	al_flip_display();
	image = al_load_bitmap("Linux.png");
	//al_draw_bitmap(image, 200, 0, 0);
	al_draw_rotated_bitmap(image, 75, 110, 200, 15, 2, 0);
	al_flip_display();

	/*while (true)
	{
		al_clear_to_color(color);
		al_flip_display();
		color.r = rand() % 255;
		color.g = rand() % 255;
		color.b = rand() % 255;
		Sleep(1000);
	}*/
	


	system("pause");
}