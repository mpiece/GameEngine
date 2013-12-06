#include "TileHandling.h"
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

std::ifstream infile("toast.txt");
TileHandling::TileHandling()
{

}


TileHandling::~TileHandling()
{
}
std::string TileHandling::read(int x, int y){

	int ratio;
	int b;

	int elementsPerRow = 12; //kom ih�g linebreak som �r 2 tecken \n
	std::string line;
	std::string retline;

	int arrayWidth = 50; //I detta fallet, eftersom 998001 �r v�rat max i textfilen.
	int coordId = (y * arrayWidth + x);
	std::string str2(std::to_string(coordId)); //v�rdet vi s�ker efter
	str2 += ",";

	ratio = elementsPerRow*(coordId);


	infile.seekg(ratio, infile.beg);//Korrekta formeln - search raden * max tecken per rad+2(f�r \n)
	std::getline(infile, retline);


	return retline;

}

