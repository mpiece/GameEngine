
#pragma once
#include<SDL.h>
#include<string>
#define PIXEL_AMOUNT 32
class Tile
{
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Renderer* renderer;
	int RealCordX;
	int RealCordY;
	int img_width;
	int img_height;

public:
	
	void draw(SDL_Rect rect);
	void setRect(int x, int y);

	SDL_Texture* getImage();
	SDL_Rect getImageRect();
	SDL_Rect* getCropRect();


	Tile();
	Tile(SDL_Renderer* renderer, std::string FilePath, int img_x, int img_y);
	~Tile();
};
