#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
using namespace std;
class Player
{
protected:
	string type;
	string state;
	ALLEGRO_BITMAP *guy;
	const char* m ;
	const char* m_aim ;
	const char* m_shoot ;
	const char* m_dead = "data/tomb.png";
public:
	virtual void aim() = 0;
	virtual void shoot() = 0;
	virtual void die()=0;
	virtual void respawn()=0;
	virtual ALLEGRO_BITMAP* getBit() { return guy; };
	void setBit(ALLEGRO_BITMAP* a) { guy = a; };
};