#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;

enum Cell {
	EMPTY, FOOD, WALL, PLAYER
};

enum Direction {
	UP, DOWN, LEFT, RIGHT
};


const int row = 25;
const int col = 25;




void fillField(Cell field[row][col], int foodx, int foody)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
				field[i][j] = WALL;
			else if (i == foodx && j == foody)
				field[i][j] = FOOD;
		}
	}
}

//void drawField(Cell field[50][50])
//{
//	system("cls");
//	for (int i = 0; i < 50; i++)
//	{
//		for (int j = 0; j < 50; j++)
//		{
//			cout << field[j][i];
//		}
//		cout << endl;
//	}
//}

struct Player
{
	int x;
	int y;
};


void main()
{
	srand(time(0));

	int foodx = rand() % (row -3) + 1;
	int foody = rand() % (col - 3) + 1;
	char key = 0;
	short angle = 0;

	//Data section
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_BITMAP* empty = nullptr;
	ALLEGRO_BITMAP* wall = nullptr;
	ALLEGRO_BITMAP* food = nullptr;
	ALLEGRO_BITMAP* player = nullptr;
	ALLEGRO_BITMAP* background = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_EVENT event;
	Cell field[row][col] = {};
	Player ghost = { row / 2, col/2 };
	Direction ghost_direction = UP;

	//Init section
	al_init();
	al_init_image_addon();
	al_install_keyboard();

	//Settings
	display = al_create_display(510, 510);
	empty = al_load_bitmap("empty.jpg");
	wall = al_load_bitmap("wall.jpg");
	food = al_load_bitmap("food.png");
	player = al_load_bitmap("snake.jpg");
	/*ALLEGRO_BITMAP* playerDown = al_load_bitmap("snake.jpg");
	ALLEGRO_BITMAP* playerRight = al_load_bitmap("snake.jpg");
	ALLEGRO_BITMAP* playerLeft = al_load_bitmap("snake.jpg");*/
	background = al_load_bitmap("background.jpg");
	
	fillField(field, foodx, foody);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	


	//Game loop

	
	while (true)
	{
		
		al_flip_display();
		//Drawing

		//al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, 0);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				/*if (field[i][j] == EMPTY)
					al_draw_bitmap(empty, i * 10, j * 10, 0);*/
				if (field[i][j] == WALL)
					al_draw_bitmap(wall, i *20, j * 20 , 0);
				else if (field[i][j] == FOOD)
				{
					//al_draw_bitmap(empty, i * 10, j * 10, 0);
					al_draw_bitmap(food, i * 20, j * 20, 0);
				}

			}
		}
		al_draw_bitmap(player, ghost.x *20, ghost.y * 20, angle);
		//al_draw_rotated_bitmap(player, 10, 10, ghost.x * 20, ghost.y * 20, angle, 0);

		//drawField(field);

		//User input
		ghost_direction == UP && field[ghost.x][ghost.y - 1] != WALL ? ghost.y--, angle = 0 : 0;
		ghost_direction == DOWN && field[ghost.x][ghost.y + 1] != WALL ? ghost.y++, angle = 2 : 0;
		ghost_direction == LEFT && field[ghost.x - 1][ghost.y] != WALL ? ghost.x-- : 0;
		ghost_direction == RIGHT && field[ghost.x + 1][ghost.y] != WALL ? ghost.x++ : 0;
		//al_wait_for_event(event_queue, &event);
		al_wait_for_event_timed(event_queue, &event, 0.0);
		al_rest(0.1);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_UP)
					ghost_direction = UP;
			else if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
				ghost_direction = DOWN;
			else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
				ghost_direction = LEFT;
			else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
				ghost_direction = RIGHT;
			else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);
		}

	
		//Game logic
		if (field[ghost.x][ghost.y] == FOOD)
		{
			field[ghost.x][ghost.y] = EMPTY;
			field[rand() % (row - 3) + 1][rand() % (col - 3) + 1] = FOOD;
		}
			
		 
	}
}