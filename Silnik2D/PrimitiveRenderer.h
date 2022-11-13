#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
#include "Point2D.h"

#ifndef primitiverenderer_h
#define primitiverenderer_h

using namespace sf;

class PrimitiveRenderer
{
private:
	RenderWindow* window;
public:
	PrimitiveRenderer(RenderWindow* window);
	void drawPoint(Point2D* point, Color color);
	void drawRectangle(Point2D* point,int width, int height, Color color);
	void drawSquare(Point2D* point,int x, Color color);
	void drawLine(Point2D* point1, Point2D* point2, Color color);
	void drawConvexShape(std::vector<Point2D> vec, Color color);
	void drawCircle(Point2D* point, float radius, Color color);
};

#endif