#pragma once
#include "SDL.h"
#include <string>
#include "Tile.h"
#include <SDL_image.h>
#include "Zone.h"
class Player
{
private:
	const int SCREEN_WIDTH = ROW*PIXEL_AMOUNT;
	const int SCREEN_HEIGHT = COLUMN*PIXEL_AMOUNT;

	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Rect camera;
	SDL_Renderer* renderer;
	int realX;
	int realY;
	int img_x;
	int img_y;
	std::string filePath;

	
	

public:
	bool hasMoved;
	int moving;
	int getRealY() const;
	int getRealX() const;
	void draw();
	void move(int i);
	void setCamera();
	void eventHandling(SDL_Event *e);
	Player(SDL_Renderer* renderer, std::string filePath);
	~Player();
};

