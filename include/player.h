#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "boundingbox.h"
#include "vector2.h"
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
	 * Renders sprite at its current x,y position
	 *
	 * @param graphics the graphics object used for rendering
	 */
	void draw(Graphics &graphics);

	/* void update
	 * Updates current position of player based on time elapsed
	 *
	 * @param elapsedTime the time elapsed since last update in loop
	 */
	void updateX(double elapsedTime);

	void updateY(double elapsedTime);

	/* void moveLeft
	 * Moves the player to the left x position and plays set animation
	 */
	void moveLeft();

	/* void moveRight
	 * Moves the player to the right x position and plays set animation
	 */
	void moveRight();

	void moveUp();

	void moveDown();

	/* void stopMoving
	 * Stops the player from moving and plays set animation
	 */
	void stopMoving();

	BoundingBox getBoundingBox();

	void handleXCollisions();

	void handleYCollisions();


private:
	AnimatedSprite sprite;
	float dx, dy;
	float x, y;
	float walkSpeed;
	float gravity;
	directions::Direction direction;
	BoundingBox bBox;
	Vector2 bBoxOffset;
	Vector2 lastPosition;

};

#endif