#pragma once
#include "DrawableObject.h"
#include "Transformable.h"
#include <SFML/Graphics.hpp>
#ifndef bitmapobject_h
#define bitmapobject_h
using namespace sf;

class BitmapObject: virtual public DrawableObject, virtual public TransformableObject
{
protected:
	Texture texture;
public:
	BitmapObject(){}
	BitmapObject(Vector2f position, Vector2u size, Texture texture)
	{
		this->setPosition(position);
		this->setSize(size);
		this->texture = texture;
	}
	virtual void draw(RenderWindow* window);
};

#endif // !bitmapobject_h