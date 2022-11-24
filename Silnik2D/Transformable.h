#pragma once
#ifndef transformable_h
#define transformable_h
#include "GameObject.h"

class TransformableObject : virtual public GameObject
{
public:
	virtual void translate(Vector2f vector);
	virtual void rotate(Vector2f& point, float alfa);
	virtual void scale(float k);
	virtual void scale(Vector2f& point, float k);
};
#endif 
