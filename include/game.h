#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "input.h"
#include "graphics.h"


class Game{
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics& graphics);
	void update(int elapsedTime);
	
	Player player;
};


#endif