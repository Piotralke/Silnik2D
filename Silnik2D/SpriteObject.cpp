#include "SpriteObject.h"

void SpriteObject::draw(RenderWindow* window)
{
	this->texture = textures->at(index);
	ConvexShape cs = ConvexShape(this->points.size());
	for (int i = 0; i < this->points.size(); i++)
	{
		cs.setPoint(i, points[i]);
	}
	cs.setTexture(&this->texture);
	window->draw(cs);
}