#pragma once
#ifndef drawableobject_h
#define drawableobject_h
#include "GameObject.h"

class DrawableObject : virtual public GameObject
{
public:
	virtual void draw(){}
	
};
#endif // !drawableobject_h
