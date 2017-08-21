#ifndef DOOR_H
#define DOOR_H

#include "boundingbox.h"
#include <string>

class Door{
public:
	Door();
	Door(BoundingBox box, std::string destination, std::string name);
	BoundingBox getBoundingBox();
	std::string getDestination();
	std::string getName();
private:
	BoundingBox box;	
	std::string destination;
	std::string name;
};





#endif