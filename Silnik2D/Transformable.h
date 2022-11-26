#pragma once
#ifndef transformable_h
#define transformable_h
#include "GameObject.h"

class TransformableObject : virtual public GameObject
{
public:
	void translate(Vector2f vector);
	void rotate(Vector2f& point, float alfa);
	void scale(Vector2f& point, float k);
};
#endif 
