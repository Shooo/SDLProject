#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2{
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2 *v);
	float x, y;
};



#endif