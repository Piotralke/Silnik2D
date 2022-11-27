/**
* @file RectangleObject.h
* @brief Plik naglowkowy RectangleObject.h
**/
#pragma once
#ifndef rectangleobject_h
#define rectangleobject_h
#include "ShapeObject.h"
/**
* @class RectangleObject
* @brief Klasa reprezentujaca prostokat
**/
class RectangleObject : public ShapeObject
{
public:

	/**
	 * @brief Konstruktor domyslny
	 */
	RectangleObject() {}
	/**
    * @brief Konstruktor z parametrami
	* @param position - pozycja
	* @param size - rozmiar
    */
    RectangleObject(Vector2f position, Vector2u size)
	:GameObject(position, size){}
	/**
	* @brief draw - Metoda do rysowania
	* @param window - Okno na ktorym rusujemy
	* @param - Kolor
	**/
	void draw(RenderWindow* window, Color color);
};

#endif

