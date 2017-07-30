/* boundingbox.h
 * Representation of a bounding box.
 * Used for logic involving collisions.
 */
#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "shared.h"

class BoundingBox{
public:
	/* Default constructor
	 *
	 */
	BoundingBox();

	/* Constructor
	 *
	 * @param x the x position of the bounding box
	 * @param y the y position of the bounding box
	 * @param width the width of the bounding box
	 * @param height the height of the bounding box
	 */
	BoundingBox(int x, int y, int width, int height);

	/* int getX
	 * Returns the x of the bounding box
	 *
	 * @return the x of the bounding box
	 */
	int getX();

	/* int getY
	 * Returns the y of the bounding box
	 *
	 * @return the y of the bounding box
	 */
	int getY();

	/* int getWidth
	 * Returns the width of the bounding box
	 *
	 * @return the width of the bounding box
	 */
	int getWidth();

	/* int getHeight
	 * Returns the height of the bounding box
	 *
	 * @return the height of the bounding box
	 */
	int getHeight();

	/* void setX
	 * Replaces the x of the bounding box with the specified value
	 *
	 * @param newx the value to replace x with
	 */
	void setX(int newx);

	/* void setY
	 * Replaces the y of the bounding box with the specified value
	 *
	 * @param newy the value to replace y with
	 */
	void setY(int newy);

	/* void setWidth
	 * Replaces the width of the bounding box with the specified value
	 *
	 * @param w the value to replace width with
	 */
	void setWidth(int w);

	/* void setHeight
	 * Replaces the height of the bounding box with the specified value
	 *
	 * @param h the value to replace height with
	 */
	void setHeight(int h);

	/* int getLeft
	 * Returns the left position of the bounding box
	 *
	 * @return the left position of the bounding box
	 */
	int getLeft();

	/* int getRight
	 * Returns the right position of the bounding box
	 *
	 * @return the right position of the bounding box
	 */
	int getRight();

	/* int getTop
	 * Returns the top position of the bounding box
	 *
	 * @return the top position of the bounding box
	 */
	int getTop();

	/* int getBottom
	 * Returns the bottom position of the bounding box
	 *
	 * @return the bottom position of the bounding box
	 */
	int getBottom();

	/* bool coolidesWith
	 * Tests with if the bounding box collides with the specified bounding box
	 *
	 * @param box the bounding box to be tested for collision
	 * @return true if the bounding box collides with the specified bounding box
	 */
	bool collidesWith(BoundingBox &box);

private:	
	int x;
	int y;
	int width;
	int height;
};

#endif