/* graphics.h
 * Handles rendering logic
 *
 */
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

class Graphics{
public:
	/* Constructor
	 * Initializes window and renderer
	 */
	Graphics();

	/* Destructor
	 * Destroys window and renderer
	 */
	~Graphics();

	/* SDL_Surface* loadImage
	 * Loads a SDL_Surface from a given image file
	 *
	 * @param filePath the path to the image to load
	 * @return pointer to the image as a new SDL_Surface
	 */
	SDL_Surface* loadImage(std::string filePath);

	/* void blitSurface
	 * Copies the texture of source rectangle onto the destination rectangle
	 *
	 * @param texture the texture to copy
	 * @param sourceRect the source rectangle to copy
	 * @param destRect the destination rectangle to copy the source rectangle onto
	 */
	void blit(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect);

	/* override void blitSurface
	 * Copies texture of source to destination with ability to flip and rotate the texture
	 *
	 * @param texture the texture to copy
	 * @param sourceRect the source rectangle to copy
	 * @param destRect the destination rectangle to copy the source rectangle onto
	 * @param angle the angle in degrees indicating the rotation applied to destination rectangle
	 * @param center point indicating point around which destRect will be rotated (NULL defaults to width/2, height/2 of destRect)
	 * @param flip the flipping action to perform onto texture
	 */
	void blit(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect,
				double angle, SDL_Point* center, SDL_RendererFlip flip);

	/* void clear
	 * Clears the renderer
	 */
	void clear();

	/* void present
	 * Presents content on backbuffer onto screen
	 */
	void present();

	/* SDL_Renderer* getRenderer
	 * Gets the renderer
	 *
	 * @return the renderer
	 */
	SDL_Renderer* getRenderer();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif
