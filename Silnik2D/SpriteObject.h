/**
* @file SpriteObject.h
* @brief Plik naglowkowy SpriteObject.h
**/
#pragma once
#ifndef spriteobject_h
#define spriteobject_h

#include "BitmapObject.h"
#include "AnimatedObject.h"
/**
* @class SpriteObject 
* @brief Klasa reprezentujaca animowany obiekt posiadajacy teksture
**/
class SpriteObject: virtual public BitmapObject,virtual public AnimatedObject
{
public:
	/**
	* @brief Konstruktor
	*/
	SpriteObject(std::vector<Texture>* textures, float switchTime, Vector2f position, Vector2u size)
		:AnimatedObject(textures,switchTime)
	{
		setSize(size);
		setPosition(position);
	}
	/**
	* @brief draw - Wirtualna metoda rysujaca
	**/
	virtual void draw(RenderWindow* window);
};
#endif // !1