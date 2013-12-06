#pragma once
#include <string>
#include "Player.h"
class TileHandling
{
public:

	TileHandling();
	~TileHandling();

	static std::string read(int x, int y);
	static void repaint(int i, const Player *player);
};

