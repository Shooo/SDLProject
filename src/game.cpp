#include <SDL2/SDL.h>
#include <string>

#include "../include/game.h"
#include "../include/graphics.h"
#include "../include/input.h"
#include "../include/sprite.h"
#include "../include/animatedsprite.h"

namespace{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game(){
}

void Game::gameLoop(){
	Graphics graphics;
	Input input;
	SDL_Event event;
	std::string filePath = "content/sprites/cat.png";
	//Sprite sprite(graphics, filePath, 0,8,64,64,100,100);
	int lastUpdateTime = SDL_GetTicks();

	AnimatedSprite sprite(graphics, filePath, 0,0,64,64,100);
	sprite.addAnimation("test",10,0,200,64,64, SDL_FLIP_HORIZONTAL);

	while(true){
		input.beginNewFrame();
		SDL_PollEvent(&event);
		if(event.type == SDL_KEYDOWN){
			if(event.key.repeat == 0){
				input.keyDownEvent(event);
			}
		}
		else if(event.type == SDL_KEYUP){
			input.keyUpEvent(event);
		}
		else if(event.type == SDL_QUIT){
			return;
		}
		if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
			printf("Exiting...\n");
			return;
		}
		if(input.wasKeyPressed(SDL_SCANCODE_SPACE)){
			sprite.setTimeToUpdate(500);
		}

	int currentTime = SDL_GetTicks();
	int elapsedTime = currentTime - lastUpdateTime;
	sprite.update(std::min(elapsedTime,MAX_FRAME_TIME));
	graphics.clear();
	sprite.playAnimation("test",false);
	lastUpdateTime = currentTime;
	sprite.draw(graphics, 100, 100);
	graphics.present();
	}
}

void Game::draw(Graphics& graphics){

}

void Game::update(float elapsedTime){

}