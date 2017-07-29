#ifndef TILE_H
#define TILE_H

#include "vector2.h"

struct SDL_Texture;

struct Tile{
	Tile();
	Tile(SDL_Texture* tileset, int tilewidth, int tileheight, Vector2 tilesetPosition, Vector2 mapPosition);

	SDL_Texture* tileset;
	int tilewidth;
	int tileheight;
	Vector2 tilesetPosition;
	Vector2 mapPosition;
};

#endif