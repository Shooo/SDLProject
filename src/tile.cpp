#include "../include/tile.h"
#include "../include/vector2.h"

#include <SDL2/SDL.h>

Tile::Tile()
{
}

Tile::Tile(SDL_Texture* tileset, int tilewidth, int tileheight, Vector2 tilesetPosition, Vector2 mapPosition) :
	tileset(tileset),
	tilewidth(tilewidth),
	tileheight(tileheight),
	tilesetPosition(tilesetPosition),
	mapPosition(mapPosition)
{
}