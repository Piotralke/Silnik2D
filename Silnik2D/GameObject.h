/**
* @file GameObject.h
* @brief Plik naglowkowy GameObject.h
**/
#pragma once
#include <SFML/Graphics.hpp>
#ifndef gameobject_h
#define gameobject_h
using namespace sf;

/**
* @class GameObject
* @brief Klasa podstawowego obiektu gry
**/
class GameObject
{
protected:
	Vector2f position;/*!<Pozycja obiektu>*/
	Vector2u size;/*!<Rozmiar obiektu>*/
public:
	/**
	* @brief GameObject - Domyslny konstruktor klasy GameObject
	**/
	GameObject() {}
	/**
	* @brief GameObject - Konstruktor klasy GameObject z parametrami
	* @param postion - Pozycja
	* @param size - Rozmiar
	**/
	GameObject(Vector2f position, Vector2u size)
	{
		this->position = position;
		this->size = size;
		points.push_back(position);
		points.push_back(Vector2f(position.x + size.x, position.y));
		points.push_back(Vector2f(position.x + size.x, position.y + size.y));
		points.push_back(Vector2f(position.x, position.y + size.y));
	}
	std::vector<Vector2f> points;/*!<Punkty rezprezentujace wierzcholki obiektu>*/
	/**
	* @brief setPosition - Ustawia pozycje
	* @param postion - Pozycja
	**/
	virtual void setPosition(Vector2f& position);
	/**
	* @brief getPosition - Pobiera pozycje
	**/
	virtual Vector2f getPosition();
	/**
	* @brief setSize - Ustawia rozmiar
	* @param size - rozmiar
	**/
	virtual void setSize(Vector2u size);
	/**
	* @brief getSize - Pobiera rozmiar
	**/
	virtual Vector2u getSize();
};
#endif // gameobject_h

