#include "../include/player.h"
#include "../include/vector2.h"
#include "../include/animatedsprite.h"
#include "../include/boundingbox.h"
#include "../include/shared.h"

#include <math.h>
#include <algorithm>

Player::Player(){

}

Player::Player(Graphics &graphics, Vector2 spawnPoint) : 
	dx(0),
	dy(0),
	x(spawnPoint.x),
	y(spawnPoint.y),
	walkSpeed(0.2),
	gravity(0.1),
	spriteWidth(16),
	spriteHeight(16),
	direction(directions::DOWN),
	bBoxWidth(10),
	bBoxHeight(20),
	isSprinting(false)
{
	sprite = AnimatedSprite(graphics, "content/sprites/characters.png", 144, 0, spriteWidth, spriteHeight, 200);
	int bBoxOffsetX = ((spriteWidth * constants::SPRITE_SCALE) - bBoxWidth) / 2;
	// int bBoxOffsetY = ((spriteHeight * constants::SPRITE_SCALE) - bBoxHeight) / 2;
	bBoxOffset = Vector2(bBoxOffsetX, 12);
	bBox = BoundingBox(spawnPoint.x + bBoxOffset.x, spawnPoint.y + bBoxOffset.y, bBoxWidth, bBoxHeight);
	lastPosition = Vector2(spawnPoint.x,spawnPoint.y);

	sprite.addAnimation("idleLeft",1,160,16,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("idleRight",1,160,32,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("idleUp",1,160,48,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("idleDown",1,160,0,spriteWidth,spriteHeight,SDL_FLIP_NONE);

	sprite.addAnimation("runLeft",3,144,16,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("runRight",3,144,32,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("runUp",3,144,48,spriteWidth,spriteHeight,SDL_FLIP_NONE);
	sprite.addAnimation("runDown",3,144,0,spriteWidth,spriteHeight,SDL_FLIP_NONE);
}

void Player::moveLeft(){
	dy = 0;
	dx = -walkSpeed;
	sprite.playAnimation("runLeft", false);
	direction = directions::LEFT;
}

void Player::moveRight(){
	dy = 0;
	dx = walkSpeed;
	sprite.playAnimation("runRight",false);
	direction = directions::RIGHT;
}

void Player::moveUp(){
	dx = 0;
	dy = -walkSpeed;
	sprite.playAnimation("runUp",false);
	direction = directions::UP;
}

void Player::moveDown(){
	dx = 0;
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

void Player::toggleSprint(bool sprint){
	if(sprint){
		walkSpeed = 0.4;
	}
	else {
		walkSpeed = 0.2;
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