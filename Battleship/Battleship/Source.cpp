#include "Functions.h"
using namespace std;



void main()
{
	//Settings
	int ship_number = 0;
	int image = 0;
	int destroyed[2] = {};

	Ships *ships_arr_user = new Ships[ships_count];
	Ships *ships_arr_enemy = new Ships[ships_count];

	Fields bat_field_user[field_size][field_size];
	Fields bat_field_enemy[field_size][field_size];

	subfield SubfieldShips[ships_count][4];
	shoots shooting[5];
	enemy_shoot_settings Settings;
	srand(time(0));



	// Current Mouse x and y positions
	int x = 0, y = 0;

	// Convertaion mouse x and y positions to field cell
	int temp_x = 0;
	int temp_y = 0;


	//INIT ALLEGRO COMPONENTS
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();


	//LOAD RESOURCES
	display = al_create_display(1150, 700);
	al_set_window_title(display, "Sea Battle");
	background = al_load_bitmap("data\\fon.png");
	ships_field_image = al_load_bitmap("data\\background2.png");
	ocean = al_load_bitmap("data\\ocean.jpg");
	green_square = al_load_bitmap("data\\1.png");
	x_img = al_load_bitmap("data\\x.png");
	f_img = al_load_bitmap("data\\false.png");
	back = al_load_bitmap("data\\back.jpg");
	middle1 = al_load_bitmap("data\\2.jpg");
	middle2 = al_load_bitmap("data\\3.jpg");
	front = al_load_bitmap("data\\front.jpg");
	single = al_load_bitmap("data\\one.jpg");
	red_square = al_load_bitmap("data\\2.png");
	aim = al_load_bitmap("data\\aim.png");
	instructions = al_load_bitmap("data\\Text.png");
	Black = al_load_bitmap("data\\22222.png");
	Table = al_load_bitmap("data\\tablo.png");
	font = al_load_font("data\\font.ttf", 22, 0);

	//Init Ship`s Parameters
	init_ships_params(ships_arr_user, back, middle1, middle2, front);
	init_ships_params(ships_arr_enemy, back, middle1, middle2, front);

	//REGISTER EVENTS
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));


	//Place Enemy`s ships
	sort_ships(ships_arr_enemy, x, y, ship_number, RANDOM, bat_field_enemy, ENEMY);

	//Take coordinates of subfield`s ships
	Ships_of_subfield(ships_arr_user, USER, SubfieldShips, true);

	////////////////
	ship_number = -1;
	///////////////

	while (drawed_ships != 10)
	{

		al_clear_to_color(al_map_rgb(15, 74, 88));
		al_draw_bitmap(ocean, 0, 0, 0);
		al_draw_bitmap(background, field1_x_indent, field1_y_indent, 0);
		al_draw_bitmap(ships_field_image, subfield1_x_indent, subfield1_y_indent, 0);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		Draw_ships_on_field(bat_field_user, ships_arr_user, USER);
		DrawSelectedShip(ships_arr_user, x, y, ship_number, bat_field_user);
		al_draw_bitmap(Black, field1_x_indent + (field_size * img_pix_size) + 10, subfield1_y_indent, 0);
		al_draw_bitmap(instructions, field1_x_indent + (field_size * img_pix_size) + 10, subfield1_y_indent, 0);
		al_draw_bitmap(Table, field1_x_indent + (field_size * img_pix_size) + 10, field1_y_indent, 0);
		al_draw_text(font, al_map_rgb(150, 150, 255), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent, 0, "Use UP or DOWN");
		al_draw_text(font, al_map_rgb(150, 150, 255), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent + 30, 0, "buttons to change");
		al_draw_text(font, al_map_rgb(150, 150, 255), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent + 60, 0, "the difficulty.");
		al_draw_text(font, al_map_rgb(240, 80, 255), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent + 90, 0, "Difficulty: ");
		Settings.mode == 1 ? al_draw_text(font, al_map_rgb(255, 0, 0), field1_x_indent + (field_size * img_pix_size) + 130, field1_y_indent + 90, 0, "Hard") : 0;
		Settings.mode == 0 ? al_draw_text(font, al_map_rgb(0, 255, 0), field1_x_indent + (field_size * img_pix_size) + 130, field1_y_indent + 90, 0, "Easy") : 0;
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
			else if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_DOWN)
				Settings.mode == HARD ? Settings.mode = EASY : Settings.mode = HARD;
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
	}

	for (int i = 0; i < ships_count; i++)
	{
		ships_arr_user[i].is_drawed = ON_SUBFIELD;
	}

	int img_index = 0;
	while (true)
	{
		//Drawing 
		
		al_clear_to_color(al_map_rgb(15, 74, 88));
		al_draw_bitmap(ocean, 0, 0, 0);
		al_draw_bitmap(background, field1_x_indent, field1_y_indent, 0);
		al_draw_bitmap(background, field2_x_indent, field2_y_indent, 0);
		al_draw_bitmap(ships_field_image, subfield1_x_indent, subfield1_y_indent, 0);
		al_draw_bitmap(ships_field_image, subfield2_x_indent, subfield2_y_indent, 0);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		Draw_ships_on_field(bat_field_user, ships_arr_user, USER);
		Draw_ships_on_field(bat_field_enemy, ships_arr_enemy, ENEMY);
		Ships_of_subfield(ships_arr_user, USER, SubfieldShips);
		Ships_of_subfield(ships_arr_enemy, ENEMY, SubfieldShips);
		al_draw_bitmap(Table, field1_x_indent + (field_size * img_pix_size) + 10, field1_y_indent, 0);
		al_draw_textf(font, al_map_rgb(0, 255, 0), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent, 0, "Your score: %d", destroyed[1]);
		al_draw_textf(font, al_map_rgb(255, 0, 0), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent + 30, 0, "Enemy`s score: %d", destroyed[0]);
		al_draw_text(font, al_map_rgb(0, 255, 0), 200, 15, 0, "Your Field");
		al_draw_text(font, al_map_rgb(255, 0, 0), 830, 15, 0, "Enemy`s Field");
		al_draw_text(font, al_map_rgb(240, 80, 255), field1_x_indent + (field_size * img_pix_size) + 15, field1_y_indent + 90, 0, "Difficulty: ");
		Settings.mode == 1 ? al_draw_text(font, al_map_rgb(255, 0, 0), field1_x_indent + (field_size * img_pix_size) + 130, field1_y_indent + 90, 0, "Hard") : 0;
		Settings.mode == 0 ? al_draw_text(font, al_map_rgb(0, 255, 0), field1_x_indent + (field_size * img_pix_size) + 130, field1_y_indent + 90, 0, "Easy") : 0;
		
		destroyed[1] == 20 ? al_draw_text(font, al_map_rgb(0, 255, 0), field1_x_indent + (field_size * img_pix_size) + 45, field1_y_indent + 210, 0, "** YOU WIN **") : 0;
		destroyed[0] == 20 ? al_draw_text(font, al_map_rgb(255, 0, 0), field1_x_indent + (field_size * img_pix_size) + 30, field1_y_indent + 210, 0, "** YOU LOOSE **") : 0;


		destroyed[0] < 20 && destroyed[1] < 20 ? al_draw_rotated_bitmap(aim, 20, 20, x, y, 0, 0) : 0;
		shooting[4].x != -1  ? al_draw_bitmap(aim, shooting[4].y * img_pix_size + field1_x_indent, shooting[4].x * img_pix_size + field1_y_indent, 0): 0;
		al_flip_display();


		//EVENTS
		event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN ? event.mouse.button = 0 : 0;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(0);
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);
		}

		if (destroyed[0] < 20 && destroyed[1] < 20)
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				x = event.mouse.x;
				y = event.mouse.y;
			}
			else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button == 1)
				{
					DrawShoots(ships_arr_enemy, bat_field_enemy, x, y, ENEMY, destroyed);
				}
				else if (event.mouse.button == 2 && ship_number >= 0 && ship_number < 10)
					ships_arr_user[ship_number].ship_pos == HORIZONTAL ? ships_arr_user[ship_number].ship_pos = VERTICAL : ships_arr_user[ship_number].ship_pos = HORIZONTAL;
			}

			enemy_shoot && destroyed[1] < 20 ? EnemyShoots(ships_arr_user, bat_field_user, shooting, Settings, destroyed) : 0;
			enemy_shoot = false;
		}
	}
}

