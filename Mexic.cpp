#include "Mexic.h"

void Mexic::aim()
{
	state = "aiming";
	guy = al_load_bitmap(m_aim);
	al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
}

void Mexic::shoot()
{
	state = "shooting";
	guy = al_load_bitmap(m_shoot);
	al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
}

void Mexic::die()
{
	state = "dead";
	guy = al_load_bitmap(m_dead);
	al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
}

void Mexic::respawn()
{
	state = "allright";
	guy = al_load_bitmap(m);
	al_convert_mask_to_alpha(guy, al_map_rgb(255, 0, 255));
}
