#pragma once
#ifndef rectangleobject_h
#define rectangleobject_h
#include "ShapeObject.h"
class RectangleObject : public ShapeObject
{
public:
	std::vector<Vector2f> points;
    RectangleObject()
	{
		
	}
	RectangleObject(Vector2f position, Vector2u size)
	{
		this->position = position;
		this->size = size;
		points.push_back(position);
		points.push_back(Vector2f(position.x+size.x,position.y));
		points.push_back(Vector2f(position.x + size.x, position.y+size.y));
		points.push_back(Vector2f(position.x , position.y+size.y));
	}
	void translate(Vector2f vector);
	void rotate(Vector2f& point, float alfa);
	void scale(Vector2f& point, float k);
	void draw(RenderWindow* window, Color color);
};

#endif

