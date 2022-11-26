#pragma once
#ifndef spriteobject_h
#define spriteobject_h

#include "BitmapObject.h"
#include "AnimatedObject.h"

class SpriteObject: virtual public BitmapObject,virtual public AnimatedObject
{
public:
	SpriteObject(std::vector<Texture>* textures, float switchTime, Vector2f position, Vector2u size)
		:AnimatedObject(textures,switchTime)
	{
		setSize(size);
		setPosition(position);
	}
	virtual void draw(RenderWindow* window);
};
#endif // !1