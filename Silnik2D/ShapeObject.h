#pragma once
#ifndef shapeobject_h
#define shapeobject_h
#include "GameObject.h"
#include "DrawableObject.h"
#include "Transformable.h"

class ShapeObject : public TransformableObject, public DrawableObject
{
	void draw();
};
#endif 
