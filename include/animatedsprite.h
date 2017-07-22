#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <string>
#include <map>
#include <vector>
#include "sprite.h"

class AnimatedSprite : public Sprite {
public:
	/* Default constructor
	 *
	 */
	AnimatedSprite();

	/* Destructor
	 *
	 */
	~AnimatedSprite();

	/* Constructor
	 * Initialization of sprite and other variables
	 *
	 * @param graphics the graphics object used for image loading and rendering
	 * @param filePath the path of image file to load
	 * @param sourceX the x position on spritesheet for source rectangle
	 * @param sourceY the y position on spritesheet for source rectangle
	 * @param width the width of source rectangle
	 * @param height the height of source rectangle
	 * @param timeToUpdate the time required to update animation to next frame
	 */
	AnimatedSprite(Graphics &graphics, std::string filePath, int sourceX, int sourceY,
					int width, int height, int timeToUpdate);

	/* void playAnimation
	 * Sets the animated sprite to play given animation
	 *
	 * @param animation the animation to play
	 * @param playOnce set to play animation once or set to keep playing after finish
	 */
	void playAnimation(std::string animation, bool playOnce);

	/* void update
	 * Updates the frame of current animation if time to update has been exceeded
	 *
	 * @param elapsedTime the time that has elapsed since last update
	 */
	void update(double elapsedTime);

	/* void draw
	 * Draws current animations current frame onto the backbuffer of renderer at x,y
	 *
	 * @param graphics the graphics object used for rendering
	 * @param x the x position to draw onto
	 * @param y the y position to draw onto
	 */
	void draw(Graphics &graphics, int x, int y);

	/* void addAnimation
	 * Creates an animation and adds to the animations map
	 *
	 * @param animation the name of the animation
	 * @param frames the number of frames the animation takes
	 * @param x the x position of the first rectangle of the animation on spritesheet
	 * @param y the y position of the first rectangle of the animation on spritesheet
	 * @param width the width of each frame
	 * @param width the height of each frame
	 */
	void addAnimation(std::string animation, int frames, int x, int y, int width, int height, SDL_RendererFlip flip);

	/* void setTimeToUpdate
	 * Sets the time required for animation to update to next frame
	 *
	 * @param updateTime the value the animation's update time will be updated to
	 */
	void setTimeToUpdate(int updateTime);

private:
	/* void clearAnimations
	 * Clears the animation map
	 */
	void clearAnimations();

	/* void stopAnimation
	 * Stops the current animation from playing
	 */
	void stopAnimation();

	/* void setVisible
	 * Sets the visibility of the current animation
	 *
	 * @param visible the value visibility will be set to
	 */
	void setVisible(bool visible);

	struct animation{
		std::vector<SDL_Rect> frames;
		SDL_RendererFlip flip;
	};

	bool isVisible;
	bool playAnimationOnce;
	double timeToUpdate;
	std::string currentAnimation;
	std::map<std::string, animation> animations;
	int frameIndex;
	double timeElapsed;
};



#endif