/* graphics.h
 * Handles logic of drawing on renderer and presenting on screen
 *
 */
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

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
	void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destRect);
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
