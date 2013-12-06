#include "Zone.h"
#include <string>
#include <sstream>
//#include <iostream> //testing

using namespace std;
Zone::Zone(SDL_Renderer *renderer, Tile &image){
	this->renderer = renderer;
	for (int r = 0; r < ROW; r++){
		for (int c = 0; c < COLUMN; c++){
			zone[c][r] = image;
		}
	}
}
Zone::Zone(){
	renderer = nullptr;
}


Zone::~Zone(){
	SDL_DestroyRenderer(renderer);

}

void Zone::setTile(std::string str, int x, int y){
	string temp;
	stringstream stream(str);
	int x2;
	int y2;
	int img_x;
	int img_y;
	
	getline(stream, str, ',');
	x2 = atoi(str.c_str());

	getline(stream, str, ',');
	y2 = atoi(str.c_str());

	getline(stream, str, ',');
	img_x = atoi(str.c_str());

	getline(stream, str, ',');
	img_y = atoi(str.c_str());
	
	
	zone[x][y].getCropRect()->x = img_x*PIXEL_AMOUNT;
	zone[x][y].getCropRect()->y = img_y*PIXEL_AMOUNT;

	
}

//Ska rita ut alla tiles som ligger i en zone
void Zone::draw(int index_x, int index_y){
	for (int r = 0; r < ROW; r++){
		for (int c = 0; c < COLUMN; c++){
	
			rect = { (c * 32) + (32 * COLUMN*index_x), (r * 32) + (32 * ROW*index_y), 32, 32 };
			
			zone[c][r].draw(rect);
			
			
		
		}
	}
}
