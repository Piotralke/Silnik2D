#pragma once
#ifndef transformable_h
#define transformable_h
#include "GameObject.h"

class TransformableObject : virtual public GameObject
{
public:
	void translate();
	void rotate();
	void scale();
};
#endif 
