#pragma once
#include "Ekran.h"


int main()
{
	al_init();
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	if (!al_install_audio()) {
		cout << "failed to initialize audio!\n" << endl;
		return -1;
	}
	if (!al_init_acodec_addon()) {
		cout << "failed to initialize acodec!\n" << endl;
		return -1;
	}

	ALLEGRO_KEYBOARD_STATE klawiatura;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *song = NULL;
	ALLEGRO_SAMPLE_INSTANCE *songIn = NULL;
	sample = al_load_sample("data/shot.ogg");
	song = al_load_sample("data/theme.ogg");
	songIn = al_create_sample_instance(song);
	al_reserve_samples(1);
	al_set_sample_instance_playmode(songIn, ALLEGRO_PLAYMODE_LOOP);
	if (!song) {
		cout << "Audio clip sample not loaded!\n" << endl;
		return -1;
	}
	if (!al_attach_sample_instance_to_mixer(songIn, al_get_default_mixer()))
	{
		cout << "Audio clip sample not loaded!\n" << endl;
		return -1;
	}
	if (!sample&&!song) {
		cout << "Audio clip sample not loaded!\n" << endl;
		return -1;
	}
	int q = 2;
	int w = 2;

	Mexic m;
	bMexic bm;
	gMexic gm;

	Cowboy c;
	gCowboy gc;
	yCowboy yc;

	Ekran e;
	Player* a=new Cowboy();
	Player* b=new Mexic();

	srand(time(NULL));
	time_t start, koniec;
	clock_t s, f;
	double czas = 0;
	double sek = std::rand() % 300 * 0.01 + 1;

	al_play_sample_instance(songIn);
	e.Initialize();
	e.Intro();
	e.Select(q, w);
	switch (q)
	{
	case 1:
		a = &c;
		break;
	case 2:
		a = &gc;
		break;
	case 3:
		a = &yc;
		break;
	}
	switch (w)
	{
	case 1:
		b = &m;
		break;
	case 2:
		b = &bm;
		break;
	case 3:
		b = &gm;
		break;
	}
	e.Display(a, b);
	al_rest(1.5);
	a->aim();
	b->aim();
	e.Display(a, b);
	e.Ready();
	al_rest(sek);
	e.Display(a, b);
	e.Go();
	s = clock();
	al_get_keyboard_state(&klawiatura);

	while (!al_key_down(&klawiatura, ALLEGRO_KEY_K) && !al_key_down(&klawiatura, ALLEGRO_KEY_S))
			{
				al_get_keyboard_state(&klawiatura);
				al_rest(0.001);
			}
		f = clock();
		czas = (double)(f - s) / (double)(CLOCKS_PER_SEC);
		al_rest(0.001);
		if (al_key_down(&klawiatura, ALLEGRO_KEY_S))
		{
			al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
			a->shoot();
			b->die();
			e.Display(a, b);
			al_rest(1.2);
			e.Shoot(czas, 1);
		}
		if (al_key_down(&klawiatura, ALLEGRO_KEY_K))
		{
			al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
			b->shoot();
			a->die();
			e.Display(a, b);
			al_rest(1.2);
			e.Shoot(czas, 2);
		}
		al_rest(2);
		a->respawn();
		b->respawn();

	al_stop_sample_instance(songIn);
	system("Pause");
	al_destroy_bitmap(a->getBit());
	al_destroy_bitmap(b->getBit());
	al_destroy_display(e.getDis());
	al_destroy_sample(sample);
	al_destroy_sample(song);
	al_destroy_sample_instance(songIn);
	return 0;
}