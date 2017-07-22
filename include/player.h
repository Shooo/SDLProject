#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "shared.h"

struct Vector2;
class Graphics;

class Player{
public:
	/* Default constructor
	 *
	 */
	Player();

	/* Constructor
	 * Initializes sprite and sets up animations
	 *
	 * @param graphics the graphics object used to load image
	 * @param spawnPoint the initial position of player
	 */
	Player(Graphics &graphics, Vector2 spawnPoint);

	/* void draw
	 * Draws the player sprite onto the render at its current x,y position
	 *
	 * @param graphics the graphics object used for rendering
	 */
	void draw(Graphics &graphics);

	/* void update
	 * Updates current position of player based on time elapsed
	 *
	 * @param elapsedTime the time elapsed since last update in loop
	 */
	void update(double elapsedTime);

	/* void moveLeft
	 * Moves the player to the left x position and plays set animation
	 */
	void moveLeft();

	/* void moveRight
	 * Moves the player to the right x position and plays set animation
	 */
	void moveRight();

	/* void stopMoving
	 * Stops the player from moving and plays set animation
	 */
	void stopMoving();
private:
	AnimatedSprite sprite;
	float dx, dy;
	float x, y;
	float walkSpeed;
	directions::Direction direction;

};

#endif