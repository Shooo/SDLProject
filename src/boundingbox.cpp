#include "../include/boundingbox.h"

BoundingBox::BoundingBox():
x(-1),
y(-1),
width(0),
height(0)
{
}

BoundingBox::BoundingBox(int x, int y, int width, int height):
x(x),
y(y),
width(width),
height(height)
{
}

int BoundingBox::getX(){
	return x;
}

int BoundingBox::getY(){
	return y;
}

int BoundingBox::getWidth(){
	return width;
}

int BoundingBox::getHeight(){
	return height;
}

void BoundingBox::setX(int newx){
	x = newx;
}

void BoundingBox::setY(int newy){
	y = newy;
}

void BoundingBox::setWidth(int w){
	width = w;
}

void BoundingBox::setHeight(int h){
	height = h;
}

int BoundingBox::getLeft(){
	return x;
}

int BoundingBox::getRight(){
	return x + width;
}

int BoundingBox::getTop(){
	return y;
}

int BoundingBox::getBottom(){
	return y + height;
}

bool BoundingBox::collidesWith(BoundingBox &box){
	if(box.getX() < 0){
		return false;
	}
	bool xOverlap= ((getRight() > box.getLeft()) && (getLeft() < box.getRight()));
	bool yOverlap= ((getBottom() > box.getTop()) && (getTop() < box.getBottom()));
	return xOverlap && yOverlap;
}