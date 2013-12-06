#include "SDL_Setup.h"
#include<iostream>

SDL_Setup::SDL_Setup(bool* quit, int screenWidth, int screenHight)
{
	window = SDL_CreateWindow("My first game!",
		100, 100, screenWidth, screenHight,
		SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);

	if (window == NULL){
		std::cerr << "Window couldn't be created" << std::endl;
		*quit = true;
	}
	renderer = SDL_CreateRenderer(window, -1,NULL);
	mainEvent = new SDL_Event();
}


SDL_Setup::~SDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}
void SDL_Setup::Begin(){
	SDL_PollEvent(mainEvent);
	
	SDL_RenderClear(renderer);
}
void SDL_Setup::End(){
	SDL_RenderPresent(renderer);
}
SDL_Renderer* SDL_Setup::getRenderer(){
	return renderer;
}

SDL_Event* SDL_Setup::getMainEvent(){
	return mainEvent;
}

SDL_Window* SDL_Setup::getWindow(){
	return window;
}