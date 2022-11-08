#pragma once
#include <SFML/Graphics.hpp>
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
	void drawLine();

};

#endif