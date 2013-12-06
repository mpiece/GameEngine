#include "Player.h"
#include "Tile.h"
#include "GameEngine.h"

Player::Player(SDL_Renderer* renderer, std::string filePath ){
	this->renderer = renderer;
	this->filePath = filePath;
	realX = 0;
	realY = 0;
	image = IMG_LoadTexture(renderer, filePath.c_str());
	

	SDL_QueryTexture(image,nullptr, nullptr,&img_x ,&img_y);
	moving = 0;

	rect = { 0, 0, 32, 32};

	crop = { 0, 0, 32, 32};	

	;
	camera = { 0, 0, SCREEN_HEIGHT, SCREEN_WIDTH };


	hasMoved = false;
}

Player::~Player(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(image);
}

void Player::draw(){
	SDL_RenderCopy(renderer, image, &crop, &rect);
}

void Player::move(int i){
	switch (i){
	case 1:
		rect.y -= 1;
		if (rect.y % 32 == 0){
			moving = 0;
			realY -= 1;
			CMain::repaint(i, this);
		}
		break;
	case 2:
		rect.x -= 1;
		if (rect.x % 32 == 0){
			moving = 0;
			realX -= 1;
			CMain::repaint(i, this);
		}
		break;
	case 3:
		rect.y += 1;
		if (rect.y % 32 == 0){
			moving = 0;
			realY += 1;
			CMain::repaint(i, this);
		}
		break;
	case 4:
		rect.x += 1;
		if (rect.x % 32 == 0){
			moving = 0;
			realX += 1;
			CMain::repaint(i, this);
		}
		break;

	}
}
void Player::setCamera(){
	camera.x = (rect.x + rect.w / 2) - SCREEN_WIDTH / 2;
	camera.y = (rect.y + rect.h / 2) - SCREEN_HEIGHT / 2;
}
int Player::getRealY() const{
	return realY;
}
int Player::getRealX() const{
	return realX;
}

void Player::eventHandling(SDL_Event *e){
	switch (e->type){
	case SDL_KEYDOWN:
		if (e->key.keysym.sym == SDLK_w){

			if (moving == 0){

				hasMoved = true;
				moving = 1;
			}
		}
		if (e->key.keysym.sym == SDLK_a){

			if (moving == 0){

				hasMoved = true;
				moving = 2;
			}
		}
		if (e->key.keysym.sym == SDLK_s){
			if (moving == 0){

				hasMoved = true;
				moving = 3;
			}
		}

		if (e->key.keysym.sym == SDLK_d){

			if (moving == 0){

				hasMoved = true;
				moving = 4;
			}
		}
		break;
	}
}