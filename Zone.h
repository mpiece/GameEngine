#pragma once
#include"SDL.h"
#include"Tile.h"
#include <string>
#define ROW 15

#define COLUMN 20
class Zone
{
	Tile zone[COLUMN][ROW];
	int index;
	SDL_Renderer* renderer;
	SDL_Rect rect;

public:
	void setTile(std::string str, int x, int y);
	void draw(int index_x, int index_y);
	Zone();
	Zone(SDL_Renderer *renderer, Tile &image);
	~Zone();
};
