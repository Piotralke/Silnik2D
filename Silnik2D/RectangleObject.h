#pragma once
#ifndef rectangleobject_h
#define rectangleobject_h
#include "ShapeObject.h"
class RectangleObject : public ShapeObject
{
public:
    RectangleObject()
	{
		
	}
	void draw(RenderWindow* window, Color color);
};

#endif

