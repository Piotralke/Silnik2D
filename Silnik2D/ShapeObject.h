/**
* @file ShapeObject.h
* @brief Plik naglowkowy ShapeObject.h
**/
#pragma once
#ifndef shapeobject_h
#define shapeobject_h
#include "GameObject.h"
#include "DrawableObject.h"
#include "Transformable.h"
/**
* @class ShapeObject
* @brief Klasa reprezentujaca figure
**/
class ShapeObject : public TransformableObject, public DrawableObject
{
	/**
	* @brief draw - Metoda do rysowania
	**/
	void draw();
};
#endif 
