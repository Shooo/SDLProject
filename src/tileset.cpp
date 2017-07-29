#include "../include/tileset.h"
#include <SDL2/SDL.h>

Tileset::Tileset(){
}

Tileset::Tileset(SDL_Texture* texture, int firstgid,int tilecount) :
	texture(texture),
	firstgid(firstgid),
	tilecount(tilecount)
{
}