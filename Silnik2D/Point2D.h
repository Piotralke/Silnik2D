#pragma once
#include "ShapeObject.h"

#ifndef point2d_h
#define point2d_h
using namespace sf;

class Point2D : public ShapeObject 
{
public:
	Point2D(float x, float y);
	Point2D();
	Point2D(Vector2f point);
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	Vector2f getVector();
	Point2D getPoint();
};

#endif