/* sprite.h
 *
 */
#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

class Graphics;

class Sprite{
public:
	/* Default Constructor
	 *
	 */
	Sprite();
	/* Constructor
	 * Initializes spritesheet texture and source rectangle of texture
	 *
	 * @param graphics the graphics object used for image load and rendering
	 * @param filePath the path of image file to load
	 * @param sourceX the x position on spritesheet for the source rectangle
	 * @param sourceY the y position on spritesheet for the source rectangle
	 * @param width the width of the source rectangle
	 * @param height the height of the source rectangle
	 * @param posX
	 * @param posY
	 */
	Sprite(Graphics &graphics, std::string filePath, int sourceX,
			int sourceY, int width, int height);
	/* Destructor
	 *
	 */
	~Sprite();
	/* void draw
	 * Draws the sprite at position x,y onto the backbuffer of the renderer
	 * 
	 * @param graphics the graphics object used for rendering
	 * @param x the x position to draw onto
	 * @param y the y position to draw onto
	 */
	void draw(Graphics& graphics, int x, int y);

protected:
	SDL_Texture* spriteSheet;
	SDL_Rect sourceRect;
};

#endif