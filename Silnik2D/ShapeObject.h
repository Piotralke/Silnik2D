#pragma once
#ifndef shapeobject_h
#define shapeobject_h
#include "GameObject.h"
#include "DrawableObject.h"
#include "Transformable.h"

class ShapeObject : public TransformableObject, public DrawableObject
{
public:
     void translate(Vector2f vector);
	 void rotate(Vector2f& point, float alfa);
	 void scale(float k);
	 void scale(Vector2f& point,float k);
	 void draw(RenderWindow* window);
	
};
#endif 
