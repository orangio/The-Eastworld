#pragma once
#include"Player.h"

class yCowboy : public Player
{
	string type;
	string state;
	ALLEGRO_BITMAP *guy;
	const char* m = "data/yellow_cowboy.bmp";
	const char* m_aim = "data/yellow_cowboy_aim.bmp";
	const char* m_shoot = "data/yellow_cowboy_shoot.bmp";
public:
	yCowboy() {
		guy = al_load_bitmap(m);
		al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
	};
	ALLEGRO_BITMAP* getBit() { return guy; };
	void aim();
	void shoot();
	void die();
	void respawn();
};
