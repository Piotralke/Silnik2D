/**
* @file DrawableObject.h
* @brief Plik naglowkowy DrawableObject.h
**/
#pragma once
#ifndef drawableobject_h
#define drawableobject_h
#include "GameObject.h"
/**
* @class DrawableObject
* @brief Klasa obiektu gry, ktory moze zostac narysowany
**/
class DrawableObject : virtual public GameObject
{
public:
	/**
	* @brief draw - Wirtualna metoda rysujaca
	**/
	virtual void draw(){}
	
};
#endif // !drawableobject_h
