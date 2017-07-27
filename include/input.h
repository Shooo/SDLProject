/* 
 * input.h
 * Handles input logic
 */

#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <map>

class Input{
public:
	Input();
	~Input();

	/* void beginNewFrame
	 * clears maps required to proccess a new frame
	 */
	void beginNewFrame();

	/* void keyUpEvent
	 * sets values in respected maps in the case of a SDL_KEYUP event
	 * 
	 * @param event the event that holds the key to put into maps
	 */
	void keyUpEvent(const SDL_Event& event);

	/* void keyDownEvent
	 * sets values in respected maps in the case of a SDL_KEYDOWN event
	 *
	 * @param event the event that holds the key to put into maps
	 */
	void keyDownEvent(const SDL_Event& event);

	/* bool wasKeyPressed
	 * returns boolean value of if key was pressed
	 *
	 * @param key the key you want the value of
	 */
	bool wasKeyPressed(SDL_Scancode key);

	/* bool wasKeyReleased
	 * returns boolean value of if key was released
	 *
	 * @param key the key you want the value of
	 */
	bool wasKeyReleased(SDL_Scancode key);

	/* bool wasKeyPressed
	 * returns boolean value of if key is held
	 *
	 * @param key the key you want the value of
	 */
	bool isKeyHeld(SDL_Scancode key);

private:
	std::map<SDL_Scancode, bool> heldKeys;
	std::map<SDL_Scancode, bool> pressedKeys;
	std::map<SDL_Scancode, bool> releasedKeys;
};

#endif