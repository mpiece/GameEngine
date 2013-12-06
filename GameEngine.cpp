#include "GameEngine.h"
#include "SDL_Setup.h"
#include <iostream>
#include <SDL_image.h>
#include <cmath>
#include "Zone.h"
#include <Windows.h>
#include <time.h>
#include "TileHandling.h"
#include <fstream>
using namespace std;
Zone *z1;

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight) : quit(false), screenWidth(passed_ScreenWidth)
, screenHeight(passed_ScreenHeight){

	setup = new SDL_Setup(&quit, screenWidth, screenHeight);

	grass = new Tile(setup->getRenderer(), "Images/background.png", 4,15);

	
	
	//	bob = new Tile(setup->getRenderer(), "Images/bob.png");


	z1 = new Zone(setup->getRenderer(), *grass);
	

	
	
	w = new World(z1);
	player = new Player(setup->getRenderer(), "Images/characters.png");

	follow = false;
	
}


CMain::~CMain()
{

	delete setup;
	delete grass;
	delete bob;
}

//borde städas bort används inte
float CMain::getDistance(float x1, float y1, float x2, float y2){
	double diffrenceX = x1 - x2;
	double diffrenceY = y1 - y2;
	return sqrt((diffrenceX*diffrenceX) + (diffrenceY*diffrenceY));
}
void CMain::GameLoop(){
	double nextGameTick;
	int check;
	string s;
	int fps = 0;
	int sec = SDL_GetTicks();
	int test = 0;
	while (!quit && setup->getMainEvent()->type != SDL_QUIT){
		nextGameTick = SDL_GetTicks();
		check = SDL_GetTicks();
		setup->Begin();
		
		
		if (player->moving > 0){
			switch (player->moving){
			case 1:
				player->move(1);
				break;
			case 2:
				player->move(2);
				break;
			case 3:
				player->move(3);
				break;
			case 4:
				player->move(4);
				break;
			}
		}
		else if (player->moving == 0 && player->hasMoved)
		
			player->hasMoved = false;

		while ((nextGameTick+16)>SDL_GetTicks()){
				
		
			
			test++;
			while (SDL_PollEvent(setup->getMainEvent())){

				player->eventHandling(setup->getMainEvent());

			}
			

		}
		
		
		z1->draw(0,0);
		player->draw();
		setup->End();
		
		//Skriver ut FPS i spelet
		fps++;
		if ((sec + 1000) <SDL_GetTicks()){
			
			std::cout << fps << "      "<< test << "         "<< s << std::endl;
			sec = SDL_GetTicks();
			test = 0;
			fps = 0;

		}
	}
	
}
/*
 
*/
void CMain::repaint(int i, const Player *player){
	string s;
	int n = 0;
	int m = 0;
	switch (i){
	case 1:

		for (int r = player->getRealY(); r < (15 + player->getRealY()); r++){
			
			for (int c = 0; c < 20; c++){
				
				s = TileHandling::read(c, r);

				z1->setTile(s, m, n);
				m++;
				//std::cout << read(1, 1) << endl;
			}
			n++;
			m = 0;
		}
		break;
	case 2:

		for (int r = 0; r < 15; r++){
			
			for (int c = player->getRealX(); c < (20 + player->getRealX()); c++){
				
				s = TileHandling::read(c, r);

				z1->setTile(s, m, n);
				m++;
				//std::cout << read(1, 1) << endl;
			}
			n++;
			m = 0;
		}
		break;
	case 3:

		for (int r = player->getRealY(); r < (15 + player->getRealY()); r++){
			
			for (int c = 0; c < 20; c++){
				
				s = TileHandling::read(c, r);

				z1->setTile(s, m, n);
				m++;
				//std::cout << read(1, 1) << endl;
			}
			n++;
			m = 0;
		}
		break;
	case 4:

		for (int r = 0; r < 15; r++){
			
			for (int c = player->getRealX(); c < (20+player->getRealX()); c++){
					
					s = TileHandling::read(c, r);
			
					z1->setTile(s, m, n);
					m++;
				//std::cout << read(1, 1) << endl;
			}
			n++;
			m = 0;
		}
		break;
	}

}
