#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/graphics.h"
#include "../include/shared.h"

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, 0, &window, &renderer);
}

Graphics::~Graphics(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

SDL_Surface* Graphics::loadImage(std::string filePath){
	if(spriteSheets.count(filePath) == 0){
		spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect){
	SDL_RenderCopy(renderer, texture, sourceRect, destRect);
}

void Graphics::clear(){
	SDL_RenderClear(renderer);
}

void Graphics::present(){
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Graphics::getRenderer(){
	return renderer;
}