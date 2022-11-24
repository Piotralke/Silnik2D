#pragma once
#include "Point2D.h"
#include "PrimitiveRenderer.h"

#ifndef linesegment_h
#define linesegment_h

using namespace sf;

class LineSegment : public ShapeObject
{
private:
	Point2D first;
	Point2D second;
public:
	LineSegment(Point2D first, Point2D second);
	Point2D getFirst();
	Point2D getSecond();
	void setFirst(Point2D point);
	void setSecond(Point2D point);
	void draw(int mode, PrimitiveRenderer* pr, Color color);
	void translate(Vector2f vector);
	void rotate(Vector2f& point, float alfa);
	void scale(Vector2f& point, float k);
};

#endif
