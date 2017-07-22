#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "shared.h"

struct Vector2;
class Graphics;

class Player{
public:
	Player();
	Player(Graphics &graphics, Vector2 spawnPoint);
	void draw(Graphics &graphics);
	void update(double elapsedTime);
	void moveLeft();
	void moveRight();
	void stopMoving();
private:
	AnimatedSprite sprite;
	float dx, dy;
	float x, y;
	float walkSpeed;
	directions::Direction direction;

};

#endif