#include <SDL2/SDL.h>
#include <string>

#include "../include/game.h"
#include "../include/graphics.h"
#include "../include/input.h"
#include "../include/sprite.h"
#include "../include/animatedsprite.h"
#include "../include/player.h"
#include "../include/vector2.h"

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
	SDL_Event event;
	Input input;
	Graphics graphics;
	player = Player(graphics, Vector2(100,100));
	int lastUpdateTime = SDL_GetTicks();

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
		else if(input.isKeyHeld(SDL_SCANCODE_LEFT)){
			player.moveLeft();
		}
		else if(input.isKeyHeld(SDL_SCANCODE_RIGHT)){
			player.moveRight();
		}
		if(!input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_LEFT)){
			player.stopMoving();
		}

	int currentTime = SDL_GetTicks();
	int elapsedTime = currentTime - lastUpdateTime;
	update(std::min(elapsedTime,MAX_FRAME_TIME));
	lastUpdateTime = currentTime;
	draw(graphics);
	}
}

void Game::draw(Graphics& graphics){
	graphics.clear();
	player.draw(graphics);
	graphics.present();
}

void Game::update(int elapsedTime){
	player.update(elapsedTime);
}