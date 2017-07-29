#include "../include/player.h"
#include "../include/vector2.h"
#include "../include/animatedsprite.h"
#include "../include/boundingbox.h"

#include <math.h>
#include <algorithm>

Player::Player(){

}

Player::Player(Graphics &graphics, Vector2 spawnPoint) : 
	sprite(graphics, "content/sprites/characters.png", 144, 0, 16, 16, 100),
	dx(0),
	dy(0),
	x(spawnPoint.x),
	y(spawnPoint.y),
	walkSpeed(0.2),
	gravity(0.1),
	direction(directions::LEFT),
	bBoxOffset(4,4)
{
	bBox = BoundingBox(spawnPoint.x + bBoxOffset.x, spawnPoint.y + bBoxOffset.y, 26, 26);
	lastPosition = Vector2(spawnPoint.x,spawnPoint.y);
	sprite.addAnimation("idleLeft",1,160,16,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("idleRight",1,160,32,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("idleUp",1,160,48,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("idleDown",1,160,0,16,16,SDL_FLIP_NONE);

	sprite.addAnimation("runLeft",3,144,16,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("runRight",3,144,32,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("runUp",3,144,48,16,16,SDL_FLIP_NONE);
	sprite.addAnimation("runDown",3,144,0,16,16,SDL_FLIP_NONE);
	sprite.playAnimation("idleLeft",false);
}



void Player::moveLeft(){
	dx = -walkSpeed;
	sprite.playAnimation("runLeft", false);
	direction = directions::LEFT;
}

void Player::moveRight(){
	dx = walkSpeed;
	sprite.playAnimation("runRight",false);
	direction = directions::RIGHT;
}

void Player::moveUp(){
	dy = -walkSpeed;
	sprite.playAnimation("runUp",false);
	direction = directions::UP;
}

void Player::moveDown(){
	dy = walkSpeed;
	sprite.playAnimation("runDown",false);
	direction = directions::DOWN;
}

void Player::stopMoving(){
	dx = 0;
	dy = 0;
	if(direction == directions::LEFT){
		sprite.playAnimation("idleLeft",false);
	}
	else if(direction == directions::RIGHT){
		sprite.playAnimation("idleRight",false);
	}
	else if(direction == directions::UP){
		sprite.playAnimation("idleUp",false);
	}
	else if(direction == directions::DOWN){
		sprite.playAnimation("idleDown",false);
	}
}

void Player::updateX(double elapsedTime){
	lastPosition.x = x;
	x += dx * elapsedTime;
	bBox.setX(x + bBoxOffset.x);
	sprite.update(elapsedTime);
}

void Player::updateY(double elapsedTime){
	lastPosition.y = y;
	y += dy * elapsedTime;
	bBox.setY(y + bBoxOffset.y);
	sprite.update(elapsedTime);
}

void Player::draw(Graphics &graphics){
	sprite.draw(graphics, x, y);
}

BoundingBox Player::getBoundingBox(){
	return bBox;
}

void Player::handleXCollisions(){
	x = lastPosition.x;
	bBox.setX(x + bBoxOffset.x);
}

void Player::handleYCollisions(){
	y = lastPosition.y;
	bBox.setY(y + bBoxOffset.y);
}