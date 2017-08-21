#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <map>

#include "tinyxml2.h"
#include "tileset.h"
#include "tile.h"
#include "boundingbox.h"
#include "door.h"

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


	/* void loadMap
	 * Parses and processes the map file
	 *
	 * @param mapName the file path of map to load
	 * @graphics the graphics object used to handle rendering
	 */
	void loadMap(std::string mapName, Graphics &graphics);

	/* void draw
	 * Renders the tiles onto screen
	 *
	 * @param graphics the graphics object for handling rendering
	 */
	void draw(Graphics &graphics);

	bool isTileColliding(BoundingBox box);

	Door getCollidingDoor(BoundingBox box);

	Vector2 getSpawnPoint(std::string name);
private:

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
	 * parses tile elements of a layer and fills the tiles' information in given Tile vector
	 *
	 * @param tileElement the first tile element to parse
	 * @param tiles the vector to fill with tile information
	 */
	void parseTiles(tinyxml2::XMLElement* tileElement, std::vector<Tile> &tiles);

	/* void parseCollisions
	 * parses tile elements of a collision layer and fills the tiles' information in a given collision vector
	 *
	 * @param tileElement the first tile element to parse
	 * @param collisions the vector to fill with collision tile information
	 */
	void parseCollisions(tinyxml2::XMLElement* tileElement, std::vector<BoundingBox> &collisions);

	void parseSpawnPoints(tinyxml2::XMLElement*);

	/* void drawTiles
	 * Renders the tiles in a given Tile vector onto the screen
	 *
	 * @param graphics the graphics object used for handling rendering
	 * @param tiles the Tile vector to draw on screen
	 */
	void drawTiles(Graphics &graphics, std::vector<Tile> &tiles);

	void parseDoors(tinyxml2::XMLElement* objectElement);

	std::string mapName;
	std::vector<Tileset> tilesets;
	std::vector<Tile> background;
	std::vector<Tile> foreground;
	std::vector<BoundingBox> collisions;
	std::vector<Door> doors;
	std::map<std::string,Vector2> spawnPoints;
	


	// width and height of map in number of tiles
	int width, height;
	int tilewidth, tileheight;
};


#endif