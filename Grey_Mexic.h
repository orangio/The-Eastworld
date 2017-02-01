#pragma once
#include"Player.h"

class gMexic : public Player
{
	string type;
	string state;
	ALLEGRO_BITMAP *guy;
	const char* m = "data/grey_mexic.png";
	const char* m_aim = "data/grey_mexic_aim.png";
	const char* m_shoot = "data/grey_mexic_shoot.png";
public:
	gMexic() {
		guy = al_load_bitmap(m);
		al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
	};
	ALLEGRO_BITMAP* getBit() { return guy; };
	void aim();
	void shoot();
	void die();
	void respawn();
};