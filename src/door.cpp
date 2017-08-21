#include "../include/door.h"
#include <string>

Door::Door():
	destination("")
{
}

Door::Door(BoundingBox box, std::string destination, std::string name):
	box(box),
	destination(destination),
	name(name)
{
}

BoundingBox Door::getBoundingBox(){
	return box;
}

std::string Door::getDestination(){
	return destination;
}

std::string Door::getName(){
	return name;
}