#include "../include/input.h"

Input::Input(){}
Input::~Input(){}

void Input::beginNewFrame(){
	releasedKeys.clear();
	pressedKeys.clear();
}

void Input::keyUpEvent(const SDL_Event& event){
	releasedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = false;
}

void Input::keyDownEvent(const SDL_Event& event){
	pressedKeys[event.key.keysym.scancode] = true;
	heldKeys[event.key.keysym.scancode] = true;
}

bool Input::wasKeyPressed(SDL_Scancode key){
	return pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key){
	return releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key){
	return heldKeys[key];
}