#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "shared.h"

class BoundingBox{
public:
	BoundingBox();
	BoundingBox(int x, int y, int width, int height);
	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void setX(int newx);
	void setY(int newy);
	void setWidth(int w);
	void setHeight(int h);

	int getLeft();
	int getRight();
	int getTop();
	int getBottom();

	bool collidesWith(BoundingBox &box);

private:	
	int x;
	int y;
	int width;
	int height;
};

#endif