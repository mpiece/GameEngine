#pragma once
#include<SDL.h>
#include "SDL_Setup.h"
#include "Tile.h"
#include "Zone.h"

#include "Player.h"

class CMain
{
	bool quit;
	bool follow;

	int timeCheck;
	int mouseX;
	int mouseY;
	int follow_x;
	int follow_y;
	int screenWidth;
	int screenHeight;
	Tile *grass;
	Tile *bob;
	Player *player;


	SDL_Setup *setup;

public:
	static void CMain::repaint(int i,const Player *player);
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain();

	void GameLoop();
	float getDistance(float x1, float y1, float x2, float y2);
};

