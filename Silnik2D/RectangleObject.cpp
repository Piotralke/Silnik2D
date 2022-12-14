#include "RectangleObject.h"
#include <iostream>

void RectangleObject::draw(RenderWindow* window, Color color)
{
	ConvexShape cs = ConvexShape(this->points.size());
	for (int i = 0; i < this->points.size(); i++)
	{
		cs.setPoint(i, points[i]);
	}
	cs.setFillColor(color);
	window->draw(cs);

}