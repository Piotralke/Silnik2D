/**
* @file BitmapObject.h
* @brief Plik naglowkowy Bitmap Object
**/
#pragma once
#include "DrawableObject.h"
#include "Transformable.h"
#include <SFML/Graphics.hpp>
#ifndef bitmapobject_h
#define bitmapobject_h
using namespace sf;
/**
* @class BitmapObject
* @brief Klasa obiektu, ktory posiada tekstury
**/
class BitmapObject: virtual public DrawableObject, virtual public TransformableObject
{
protected:
	Texture texture;/*!<Instancja tekstury>*/
public:
	/**
	* @brief Domyslny konstruktor
	**/
	BitmapObject(){}
	/**
	* @brief Konstruktor z parametrami
	* @param position Pozycja bitmapy
	* @param size Rozmiar bitmapy
	* @param texture Wskaznik na teksture bitmapy
	**/
	BitmapObject(Vector2f position, Vector2u size, Texture* texture)
		:GameObject(position,size)
	{
		this->setPosition(position);
		this->setSize(size);
		this->texture = *texture;
	}
	/**
	* @brief Podstawowa funkcja wyswietlajaca teksture
	* @param window wskaznik na okno, na ktorym ma narysowac teksture
	**/
	virtual void draw(RenderWindow* window);
};

#endif // !bitmapobject_h