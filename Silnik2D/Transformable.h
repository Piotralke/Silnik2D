/**
* @file Transformable.h
* @brief Plik naglowkowy Transformable
**/
#pragma once
#ifndef transformable_h
#define transformable_h
#include "GameObject.h"
/**
* @class TransformableObject
* @brief Klasa reprezentujaca transformujacy objekt
**/
class TransformableObject : virtual public GameObject
{
public:
    /**
	* @brief translate - Funkcja umozliwiajaca przesuwanie
	* @param vector - Wektor przemieszczenia
	**/
	void translate(Vector2f vector);
    /**
	* @brief rotate - Funkcja umozliwiajaca obracanie
	* @param point - Wspolrzedne punktu wobec ktorego ma wykonac obrot
	* @param alfa - Kat o jaki ma obrocic
	**/
	void rotate(Vector2f& point, float alfa);
    /**
    * @brief scale - Funkcja umozliwiajaca skalowanie
    * @param point - Wspolrzedne punktu wobec ktorego ma wykonac skalowanie
    * @param k - Wspolczynnik skalowania
    **/
	void scale(Vector2f& point, float k);
};
#endif 
