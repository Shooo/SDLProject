#include "../include/animatedsprite.h"
#include "../include/graphics.h"
#include "../include/shared.h"


AnimatedSprite::AnimatedSprite(){

}

AnimatedSprite::AnimatedSprite(Graphics &graphics, std::string filePath, int sourceX,
				int sourceY, int width, int height, int timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height),
	isVisible(true),
	playAnimationOnce(false),
	timeToUpdate(timeToUpdate),
	currentAnimation(""),
	timeElapsed(0)
{

}

AnimatedSprite::~AnimatedSprite(){

}

void AnimatedSprite::playAnimation(std::string animation, bool playOnce){
	playAnimationOnce = playOnce;
	if(currentAnimation != animation){
		currentAnimation = animation;
		frameIndex = 0;
	}
}

void AnimatedSprite::update(int elapsedTime){
	timeElapsed += elapsedTime;

	// if elapsed time exceeded set update time, update frame
	if(timeElapsed > timeToUpdate){
		timeElapsed -= timeToUpdate;
		// if current frame index is not at the last frame, move to next frame
		if((unsigned)frameIndex < animations[currentAnimation].frames.size() - 1){
			frameIndex++;
		}
		else{
			if(playAnimationOnce){
				setVisible(false);
			}
			frameIndex = 0;
		}
	}
}

void AnimatedSprite::addAnimation(std::string animation, int frames, int x, int y, int width, int height, SDL_RendererFlip flip){
	std::vector<SDL_Rect> rectangles;
	for(int i = 0; i < frames; i++){
		SDL_Rect rect = {x + (width * i), y, width, height};
		rectangles.push_back(rect);
	}
	animations[animation].frames = rectangles;
	animations[animation].flip = flip;
}

void AnimatedSprite::setTimeToUpdate(int updateTime){
	timeToUpdate = updateTime;
}

void AnimatedSprite::draw(Graphics &graphics, int x, int y){
	if(isVisible){
		SDL_Rect destRect = {x, y, sourceRect.w * constants::SPRITE_SCALE, sourceRect.h * constants::SPRITE_SCALE};
		graphics.blit(spriteSheet, &animations[currentAnimation].frames[frameIndex], &destRect, 0.0, NULL, animations[currentAnimation].flip);
	}
}

void AnimatedSprite::stopAnimation(){
	frameIndex = 0;
}

void AnimatedSprite::setVisible(bool visible){
	isVisible = visible;
}