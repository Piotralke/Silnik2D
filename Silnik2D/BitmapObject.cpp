#include "BitmapObject.h"

void BitmapObject::draw(RenderWindow* window)
{
	ConvexShape cs = ConvexShape(this->points.size());
	for (int i = 0; i < this->points.size(); i++)
	{
		cs.setPoint(i, points[i]);
	}
	cs.setPosition(getPosition());
	cs.setTexture(&this->texture);
	window->draw(cs);

}