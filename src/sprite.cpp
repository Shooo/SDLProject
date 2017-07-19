#include "../include/sprite.h"
#include "../include/graphics.h"


Sprite::Sprite(){

}

Sprite::~Sprite(){

}

Sprite::Sprite(Graphics &graphics, std::string filePath, int sourceX,
			int sourceY, int width, int height) : 
	flip(SDL_FLIP_NONE),
	angle(0)
{
	sourceRect.x = sourceX;
	sourceRect.y = sourceY;
	sourceRect.w = width;
	sourceRect.h = height;
	
	spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
}

void Sprite::draw(Graphics &graphics, int x, int y){
	SDL_Rect destRect = {x, y, sourceRect.w, sourceRect.h};
	graphics.blit(spriteSheet, &sourceRect, &destRect);
}

SDL_Texture* Sprite::getSpriteSheet(){
	return spriteSheet;
}