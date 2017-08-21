#include <string>
#include <vector>
#include <iostream>
#include "../include/tinyxml2.h"
#include "../include/level.h"
#include "../include/graphics.h"
#include "../include/tileset.h"
#include "../include/tile.h"
#include "../include/door.h"
#include "../include/shared.h"


using namespace tinyxml2;

Level::Level(){

}
Level::Level(std::string mapName, Graphics &graphics)
{
	loadMap(mapName, graphics);
}

Level::~Level(){

}

void Level::loadMap(std::string mapName, Graphics &graphics){
	XMLDocument doc;
	mapName = "content/maps/" + mapName + ".tmx";
	XMLError result = doc.LoadFile(mapName.c_str());
	XMLCheckResult(result);

	XMLElement* mapElement = doc.FirstChildElement("map");
	mapElement->QueryIntAttribute("width",&width);
	mapElement->QueryIntAttribute("height",&height);

	mapElement->QueryIntAttribute("tilewidth",&tilewidth);
	mapElement->QueryIntAttribute("tileheight",&tileheight);

	// Loading tilesets
	XMLElement* tilesetElement = mapElement->FirstChildElement("tileset");
	if(tilesetElement){
		parseTilesets(tilesetElement, graphics);
	}

	// Processing layers
	XMLElement* layerElement = mapElement->FirstChildElement("layer");
	if(layerElement){
		while(layerElement){
			const char* name = layerElement->Attribute("name");
			XMLElement* dataElement = layerElement->FirstChildElement("data");
			if(dataElement){
				while(dataElement){
					// Process tiles
					XMLElement* tileElement = dataElement->FirstChildElement("tile");
					if(tileElement){
						if(strcmp(name,"background") == 0){
							parseTiles(tileElement, background);
						}
						else if(strcmp(name,"foreground") == 0){
							parseTiles(tileElement, foreground);
						}
						else if(strcmp(name, "collisions") == 0){
						 	parseCollisions(tileElement, collisions);
						 }
					}
					dataElement = dataElement->NextSiblingElement("data");
				}
			}
			layerElement = layerElement->NextSiblingElement("layer");
		}
	}

	// Processing object groups
	XMLElement* objectGroupElement = mapElement->FirstChildElement("objectgroup");
	if(objectGroupElement){
		while(objectGroupElement){
			const char* name = objectGroupElement->Attribute("name");
			XMLElement* objectElement = objectGroupElement->FirstChildElement("object");
			if(strcmp(name,"doors") == 0){
				parseDoors(objectElement);
			}
			if(strcmp(name,"spawnpoints") == 0){
				parseSpawnPoints(objectElement);
			}
			objectGroupElement = objectGroupElement->NextSiblingElement("objectgroup");
		}
	}
}

void Level::XMLCheckResult(tinyxml2::XMLError result){
	if(result != XML_SUCCESS){
		printf("Error: %d\n", result);
	}
}

void Level::parseTilesets(tinyxml2::XMLElement* tilesetElement, Graphics &graphics){

	while(tilesetElement){
		const char* source = tilesetElement->FirstChildElement("image")->Attribute("source");
		// the 3 is to remove the '../' in the source string
		std::string path = "content/" + std::string(source,3,std::string::npos);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(graphics.getRenderer(),graphics.loadImage(path.c_str()));

		Tileset tileset;
		tileset.texture = texture;
		tileset.firstgid = tilesetElement->IntAttribute("firstgid");
		tileset.tilecount = tilesetElement->IntAttribute("tilecount");

		tilesets.push_back(tileset);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

void Level::parseTiles(tinyxml2::XMLElement* tileElement, std::vector<Tile> &tiles){
	int tileCounter = 0;
	while(tileElement){
		int gid = tileElement->IntAttribute("gid");
		if(gid > 0){
			Tileset tileset;
			for(unsigned int i = 0; i < tilesets.size(); i++){
				if((gid >= tilesets[i].firstgid) && (gid < tilesets[i].firstgid + tilesets[i].tilecount)){
					tileset = tilesets[i];
				}
			}
			// mod width calculates the x position for each 'layer' or 'slice' of the map
			int mapX = (tileCounter % width) * tilewidth;
			// divide by width calculates y position or which 'layer' due to truncation
			int mapY = (tileCounter / width) * tileheight;
			Vector2 mapPosition = Vector2(mapX * constants::SPRITE_SCALE, mapY * constants::SPRITE_SCALE);

			int tilesetWidth, tilesetHeight;
			SDL_QueryTexture(tileset.texture, NULL, NULL, &tilesetWidth, &tilesetHeight);
			// gid - tileset.firstgid gives the id of tile relative to its own tileset 
			// note that tielsetWidth is in number of pixels where as width is in number of tiles
			int tilesetX = ((gid - tileset.firstgid)  * tilewidth) % tilesetWidth;
			int tilesetY = (((gid - tileset.firstgid) * tilewidth) / tilesetWidth) * tileheight;
			Vector2 tilesetPosition = Vector2(tilesetX, tilesetY);

			Tile tile = Tile(tileset.texture, tilewidth, tileheight, tilesetPosition, mapPosition);
			tiles.push_back(tile);
		}
		tileCounter++;		
		tileElement = tileElement->NextSiblingElement("tile");
	}
}

void Level::parseCollisions(tinyxml2::XMLElement* tileElement, std::vector<BoundingBox> &collisions){
	int tileCounter = 0;
	while(tileElement){
		int gid = tileElement->IntAttribute("gid");
		if(gid > 0){
			int x = ((tileCounter % width) * tilewidth) * constants::SPRITE_SCALE;
			int y = ((tileCounter / width) * tileheight) * constants::SPRITE_SCALE;
			BoundingBox box(x, y, tilewidth * constants::SPRITE_SCALE,tileheight * constants::SPRITE_SCALE);
			collisions.push_back(box);
		}
		else{
			BoundingBox box;
			collisions.push_back(box);
		}
		tileCounter++;
		tileElement = tileElement->NextSiblingElement("tile");
	}
}

void Level::parseDoors(tinyxml2::XMLElement* objectElement){
	while(objectElement){
		float x = objectElement->FloatAttribute("x") * constants::SPRITE_SCALE;
		float y = objectElement->FloatAttribute("y") * constants::SPRITE_SCALE;
		float width = objectElement->FloatAttribute("width") * constants::SPRITE_SCALE;
		float height = objectElement->FloatAttribute("height") * constants::SPRITE_SCALE;
		const char* tempName = objectElement->Attribute("name");
		std::string doorName = std::string(tempName);
		BoundingBox box = BoundingBox(x,y,width,height);
		std::string destination;
		XMLElement* propertiesElement = objectElement->FirstChildElement("properties");
		if(propertiesElement){
			printf("Theres a properties\n");
			while(propertiesElement){
				printf("in properties loop\n");
				XMLElement* propertyElement = propertiesElement->FirstChildElement("property");
				if(propertyElement){
					while(propertyElement){
						const char* name = propertyElement->Attribute("name");
						if(strcmp(name,"destination") == 0){
							const char* value = propertyElement->Attribute("value");
							destination = std::string(value);
						}
						propertyElement = propertyElement->NextSiblingElement("property");
					}
				}
				propertiesElement = propertiesElement->NextSiblingElement("properties");
			}
		}
		Door door = Door(box, destination, doorName);
		doors.push_back(door);
		objectElement = objectElement->NextSiblingElement("object");
	}
}

void Level::parseSpawnPoints(tinyxml2::XMLElement* objectElement){
	while(objectElement){
		float x = objectElement->FloatAttribute("x") * constants::SPRITE_SCALE;
		float y = objectElement->FloatAttribute("y") * constants::SPRITE_SCALE;
		const char* name = objectElement->Attribute("name");
		spawnPoints[std::string(name)] = Vector2(x,y);
		objectElement = objectElement->NextSiblingElement("object");
	}
}

bool Level::isTileColliding(BoundingBox box){
	std::vector<BoundingBox> collisionBoxes;
	int leftTile = box.getLeft() / (tilewidth * constants::SPRITE_SCALE);
	int rightTile = box.getRight() / (tilewidth * constants::SPRITE_SCALE);
	int topTile = box.getTop() / (tileheight * constants::SPRITE_SCALE);
	int bottomTile = box.getBottom() / (tileheight * constants::SPRITE_SCALE);

	if(leftTile < 0){
		leftTile = 0;
	}
	if(rightTile > width){
		rightTile = width;
	}
	if(topTile < 0){
		topTile = 0;
	}
	if(bottomTile > height){
		bottomTile = height;
	}
	
	for(int i = leftTile; i <= rightTile; i++){
		for(int j = topTile; j <= bottomTile; j++){
			int index = j * width + i;
			BoundingBox otherBox = collisions[index];
			if(box.collidesWith(otherBox)){
				return true;
			}
		}
	}
	return false;
}

Door Level::getCollidingDoor(BoundingBox box){
	Door door;
	for(unsigned int i = 0; i < doors.size(); i++){
		if(doors[i].getBoundingBox().collidesWith(box)){
			printf("%s\n",doors[i].getDestination().c_str());
			door = doors[i];
			return door;
		}
	}
	return door;
}

Vector2 Level::getSpawnPoint(std::string name){
	return spawnPoints[name];
}

void Level::draw(Graphics &graphics){
	drawTiles(graphics, background);
	drawTiles(graphics, foreground);
}

void Level::drawTiles(Graphics &graphics, std::vector<Tile> &tiles){
	for(unsigned int i = 0; i < tiles.size(); i++){
		SDL_Rect sourceRect = {
			(int) tiles[i].tilesetPosition.x,
			(int) tiles[i].tilesetPosition.y,
			tiles[i].tilewidth,
			tiles[i].tileheight
		};
		SDL_Rect destRect = {
			(int) tiles[i].mapPosition.x,
			(int) tiles[i].mapPosition.y,
			tiles[i].tilewidth * constants::SPRITE_SCALE,
			tiles[i].tileheight * constants::SPRITE_SCALE
		};
		graphics.blit(tiles[i].tileset, &sourceRect, &destRect);
	}
}