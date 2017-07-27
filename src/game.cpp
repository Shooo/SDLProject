#include <SDL2/SDL.h>
#include <string>

#include "../include/game.h"
#include "../include/graphics.h"
#include "../include/input.h"
#include "../include/sprite.h"
#include "../include/animatedsprite.h"
#include "../include/player.h"
#include "../include/vector2.h"
#include "../include/level.h"

namespace{
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() :
gameIsRunning(true)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game(){
}

void Game::gameLoop(){
	SDL_Event event;
	Input input;
	Graphics graphics;
	level = Level("content/maps/map1.tmx",graphics);
	player = Player(graphics, Vector2(0,0));
	double lastTime = SDL_GetTicks();
	double lag = 0.0;

	while(gameIsRunning){
		double currentTime = SDL_GetTicks();
		double elapsedTime = currentTime - lastTime;
		lastTime = currentTime;
		lag += elapsedTime;
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
			gameIsRunning = false;
			continue;
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
		while(lag >= MAX_FRAME_TIME){
			update(MAX_FRAME_TIME);
			lag -= MAX_FRAME_TIME;
		}
		draw(graphics);
	}
}

void Game::draw(Graphics& graphics){
	graphics.clear();
	level.draw(graphics);
	player.draw(graphics);
	graphics.present();
}

void Game::update(double elapsedTime){
	player.update(elapsedTime);
}