#pragma once
#include<allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include <stdio.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include<iostream>
#include<cstdlib>
#include <ctime>


#include"Cowboy.h"
#include"Grey_Cowboy.h"
#include"Yellow_Cowboy.h"
#include"Mexic.h"
#include"BlueMexic.h"
#include"Grey_Mexic.h"

class Ekran
{
	int height;
	int width;
	ALLEGRO_DISPLAY *okno;
	ALLEGRO_FONT    *font = al_create_builtin_font();
	ALLEGRO_FONT *font_t = al_load_ttf_font("data/jackport.ttf", 36, 0);
public:
	Ekran();
	int getHe();
	int getWi();
	void Initialize();
	void Display(Player*, Player*);
	void Intro();
	void Select(int& a, int& b);
	void Ready();
	void Shoot(double, int);
	void Go();
	ALLEGRO_DISPLAY* getDis() { return okno; };
};