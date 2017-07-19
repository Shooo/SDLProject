#include "../include/player.h"
#include "../include/vector2.h"
#include "../include/animatedsprite.h"

Player::Player(){

}

Player::Player(Graphics &graphics, Vector2 spawnPoint) : 
	sprite(graphics, "content/sprites/cat.png", 0, 8, 64, 64, 100),
	dx(0),
	dy(0),
	x(spawnPoint.x),
	y(spawnPoint.y),
	walkSpeed(0.2)
{
	sprite.addAnimation("runRight",10,0,200,64,64,SDL_FLIP_NONE);
	sprite.addAnimation("runLeft",10,0,200,64,64,SDL_FLIP_HORIZONTAL);
	sprite.playAnimation("runRight",false);
}

void Player::moveRight(){
	dx = walkSpeed;
	sprite.playAnimation("runRight",false);
}

void Player::moveLeft(){
	dx = -walkSpeed;
	sprite.playAnimation("runLeft", false);
}

void Player::stopMoving(){
	dx = 0;
	sprite.playAnimation("runLeft",false);
}

void Player::update(int elapsedTime){
	x += dx * elapsedTime;
	sprite.update(elapsedTime);
}

void Player::draw(Graphics &graphics){
	sprite.draw(graphics, x, y);
}