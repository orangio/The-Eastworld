#pragma once
#include"Player.h"

class Cowboy : public Player
{
	string type;
	string state;
	ALLEGRO_BITMAP *guy;
	const char* m = "data/cowboy.bmp";
	const char* m_aim = "data/cowboy_aim.bmp";
	const char* m_shoot = "data/cowboy_shoot.bmp";
public:
	Cowboy() {
		guy = al_load_bitmap(m);
		al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
	};
	ALLEGRO_BITMAP* getBit() { return guy; };
	void aim();
	void shoot();
	void die();
	void respawn();
};