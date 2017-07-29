#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

#include "tinyxml2.h"
#include "tileset.h"
#include "tile.h"
#include "boundingbox.h"

class Graphics;

class Level{
public:
	/* Default constructor
	 *
	 */
	Level();

	/* Constructor
	 * Initializes and loads map
	 *
	 * @param mapName the file path of map to load
	 * @param graphics the graphics object used to handle rendering
	 */
	Level(std::string mapName, Graphics &graphics);

	/* Destructor
	 *
	 */
	~Level();

	/* void draw
	 * Renders the tiles onto screen
	 *
	 * @param graphics the graphics object for handling rendering
	 */
	void draw(Graphics &graphics);

	bool isColliding(BoundingBox box);
private:

	/* void loadMap
	 * Parses and processes the map file
	 *
	 * @param mapName the file path of map to load
	 * @graphics the graphics object used to handle rendering
	 */
	void loadMap(std::string mapName, Graphics &graphics);

	/* void XMLCheckResult
	 * Checks result of tinyxml2 function
	 *
	 * @param result the result to check for error
	 */
	void XMLCheckResult(tinyxml2::XMLError result);

	/* void parseTilesets
	 * parses given tileset element and following tileset elements of a tmx map
	 *
	 * @param tilesetElement the tileset element to parse
	 * @param graphics the graphics object used for rendering logic
	 */
	void parseTilesets(tinyxml2::XMLElement* tilesetElement, Graphics &graphics);

	/* void parseTiles
	 * parses given tile element and following tileset elements of a tmx map
	 *
	 * @param tileElement the tile element to parse
	 */
	void parseTiles(tinyxml2::XMLElement* tileElement, std::vector<Tile> &tiles);

	void parseCollisions(tinyxml2::XMLElement* tileElement, std::vector<BoundingBox> &collisions);

	void drawTiles(Graphics &graphics, std::vector<Tile> &tiles);

	std::string mapName;
	std::vector<Tileset> tilesets;
	std::vector<Tile> background;
	std::vector<Tile> foreground;
	std::vector<BoundingBox> collisions;
	


	// width and height of map in number of tiles
	int width, height;
	int tilewidth, tileheight;
};


#endif