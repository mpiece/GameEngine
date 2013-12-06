#include "Tile.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


Tile::Tile(SDL_Renderer* passed_renderer, std::string FilePath, int img_x, int img_y) :
renderer(passed_renderer)
{


	image = IMG_LoadTexture(renderer, FilePath.c_str());
	
	//G�r en rektangel som vi kommer rita i.
	
	
	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);
	
	
	rect = { 0, 0, img_width, img_height };
	
	//G�r en rektangel f�r att kunna klippa ut fr�n sprite layout       
	// m�jlig l�sning f�r finare kodning av talet 16 nedan (img_width / 32)
	crop = { PIXEL_AMOUNT*img_x, PIXEL_AMOUNT*img_y, img_width / 16, img_height / 16 };
	
	
	//koll att det g�r att l�sa in filen
	if (image == NULL){
		std::cerr << "Couldn't load" << FilePath << std::endl;
	}

}
Tile::Tile(){
	image = NULL;
	renderer = NULL;
	rect = { 0, 0, 50, 50 };
}

Tile::~Tile()
{
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);


}
void Tile::draw(SDL_Rect rect){
	SDL_RenderCopy(renderer, image, &crop, &rect);
}

//anv�nds inte b�r st�das bort
void Tile::setRect(int x, int y){
	rect.x = x;
	rect.y = y;
}
//getMetoder
SDL_Rect Tile::getImageRect(){
	return rect;
}
SDL_Rect* Tile::getCropRect(){
	return &crop;
}

SDL_Texture* Tile::getImage(){
	return image;
}





