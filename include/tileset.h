#ifndef TILESET_H
#define TILESET_H

struct SDL_Texture;

struct Tileset{
	Tileset();
	Tileset(SDL_Texture* texture, int firstgid, int tilecount);

	SDL_Texture* texture;
	int firstgid;
	int tilecount;
};


#endif