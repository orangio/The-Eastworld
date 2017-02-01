#include "Ekran.h"
Ekran::Ekran()
{
	height = 320;
	width = 600;
}

int Ekran::getHe()
{
	return height;
}

int Ekran::getWi()
{
	return width;
}

void Ekran::Initialize()
{
	okno = al_create_display(width, height);
	al_set_window_title(okno, "The Eastworld");
	al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
	al_flip_display();
}

void Ekran::Display(Player *a, Player *b)
{
	al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
	al_draw_scaled_bitmap(a->getBit(), 0, 0, 47, 40, 100, 100, 188, 160, 0);
	al_draw_scaled_bitmap(b->getBit(), 0, 0, 47, 40, 350, 100, 188, 160, 0);
	al_flip_display();
	al_rest(2);
}

void Ekran::Intro()
{
	al_draw_textf(font_t, al_map_rgb(0, 0, 0), 320, 80, ALLEGRO_ALIGN_CENTRE, "WITAJ W THE EASTWORLD");
	al_flip_display();
	al_rest(1.8);
}

void Ekran::Select(int& a, int& b)
{
	ALLEGRO_KEYBOARD_STATE klawiatura;
	ALLEGRO_BITMAP *arrow;
	arrow = al_load_bitmap("data/arrow.bmp");
	al_convert_mask_to_alpha(arrow, al_map_rgb(255, 0, 255));

	al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
	al_draw_textf(font_t, al_map_rgb(0, 0, 0), 320, 80, ALLEGRO_ALIGN_CENTRE, "WYBIERZ GRACZA");
	al_flip_display();
	al_rest(1.8);
	int x = 120;
	int z = 120;
	{
		Cowboy c;
		gCowboy g;
		yCowboy y;
		al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
		al_draw_scaled_bitmap(c.getBit(), 0, 0, 47, 40, 100, 100, 188, 160, 0);
		al_draw_scaled_bitmap(arrow, 0, 0, 47, 40, 120, 10, 141, 120, 0);
		al_draw_scaled_bitmap(g.getBit(), 0, 0, 47, 40, 220, 100, 188, 160, 0);
		al_draw_scaled_bitmap(y.getBit(), 0, 0, 47, 40, 340, 100, 188, 160, 0);
		al_flip_display();

		al_get_keyboard_state(&klawiatura);
		while (!al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
		{
			al_get_keyboard_state(&klawiatura);
			al_rest(0.1);
			al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
			al_draw_scaled_bitmap(c.getBit(), 0, 0, 47, 40, 100, 100, 188, 160, 0);
			al_draw_scaled_bitmap(arrow, 0, 0, 47, 40, x, 10, 141, 120, 0);
			al_draw_scaled_bitmap(g.getBit(), 0, 0, 47, 40, 220, 100, 188, 160, 0);
			al_draw_scaled_bitmap(y.getBit(), 0, 0, 47, 40, 340, 100, 188, 160, 0);
			al_flip_display();
			if (al_key_down(&klawiatura, ALLEGRO_KEY_LEFT))
			{
				x = x - 120;
				if (x == 00)
					x = 360;
			}
			if (al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT))
			{
				x = x + 120;
				if (x == 480)
					x = 120;
			}
		}
	}
	a = x / 120;
	al_get_keyboard_state(&klawiatura);
	{
		Mexic c;
		bMexic g;
		gMexic y;
		al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
		al_draw_scaled_bitmap(c.getBit(), 0, 0, 47, 40, 30, 100, 188, 160, 0);
		al_draw_scaled_bitmap(arrow, 0, 0, 47, 40, 120, 10, 141, 120, 0);
		al_draw_scaled_bitmap(g.getBit(), 0, 0, 47, 40, 150, 100, 188, 160, 0);
		al_draw_scaled_bitmap(y.getBit(), 0, 0, 47, 40, 270, 100, 188, 160, 0);
		al_flip_display();

		al_get_keyboard_state(&klawiatura);
		while (!al_key_down(&klawiatura, ALLEGRO_KEY_ENTER))
		{
			al_get_keyboard_state(&klawiatura);
			al_rest(0.1);
			al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
			al_draw_scaled_bitmap(c.getBit(), 0, 0, 47, 40, 30, 100, 188, 160, 0);
			al_draw_scaled_bitmap(arrow, 0, 0, 47, 40, z, 10, 141, 120, 0);
			al_draw_scaled_bitmap(g.getBit(), 0, 0, 47, 40, 150, 100, 188, 160, 0);
			al_draw_scaled_bitmap(y.getBit(), 0, 0, 47, 40, 270, 100, 188, 160, 0);
			al_flip_display();
			if (al_key_down(&klawiatura, ALLEGRO_KEY_LEFT))
			{
				z = z - 120;
				if (z == 00)
					z = 360;
			}
			if (al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT))
			{
				z = z + 120;
				if (z == 480)
					z = 120;
			}
		}
	}
	b = z / 120;
}
void Ekran::Ready()
{
	al_draw_textf(font_t, al_map_rgb(0, 0, 0), 320, 40, ALLEGRO_ALIGN_CENTRE, "Przygotuj sie!");
	al_flip_display();
}
void Ekran::Shoot(double d, int a)
{
	ALLEGRO_SAMPLE *sample = NULL;
	al_clear_to_color(al_map_rgb_f(0.5, 0.5, 0.5));
	al_draw_textf(font_t, al_map_rgb(255, 0, 0), 320, 40, ALLEGRO_ALIGN_CENTRE, "STRZELIL GRACZ %d , Po %.2f sekundy", a, d);
	al_flip_display();
}
void Ekran::Go()
{
	al_draw_textf(font_t, al_map_rgb(255, 0, 0), 320, 40, ALLEGRO_ALIGN_CENTRE, "STRZAL");
	al_flip_display();
}


