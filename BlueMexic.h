#pragma once
#include"Player.h"

class bMexic : public Player
{
	string type;
	string state;
	ALLEGRO_BITMAP *guy;
	const char* m = "data/blue_mexic.png";
	const char* m_aim = "data/blue_mexic_aim.png";
	const char* m_shoot = "data/blue_mexic_shoot.png";
public:
	bMexic() {
		guy = al_load_bitmap(m);
		al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
	};
	ALLEGRO_BITMAP* getBit() { return guy; };
	void aim();
	void shoot();
	void die();
	void respawn();
};
