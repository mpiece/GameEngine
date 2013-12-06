#pragma once
#include<SDL.h>
class SDL_Setup
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
public:
	void Begin();
	void End();
	SDL_Renderer* getRenderer();
	SDL_Event* getMainEvent();
	SDL_Window* getWindow();
	SDL_Setup(bool* quit, int screenWidth, int screenHight);
	~SDL_Setup();
};

