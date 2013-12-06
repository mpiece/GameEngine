

#include "GameEngine.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	CMain* cmain = new CMain(COLUMN*PIXEL_AMOUNT, ROW*PIXEL_AMOUNT);
	
	
	cmain->GameLoop();
	delete cmain;

	return 0;
}