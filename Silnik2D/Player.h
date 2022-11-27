/**
* @file Player.h
* @brief Plik naglowkowy Player.h
**/
#pragma once
#ifndef player_h
#define player_h
#include "SpriteObject.h"
/**
* @class Player
* @brief Klasa gracza
**/
class Player : public SpriteObject
{
public:
	ConvexShape cs = ConvexShape(this->points.size());/*!<Obiekt do manipulacji graczem>*/
	/**
	* @brief Player - Konstruktor klasy Player z parametrami
	* @param textures - vector tekstur do animacji
	* @param switchTime - czas pomiedzy klatkami animacji
	* @param position - pozycja
	* @param size - rozmiar
	**/
	Player(std::vector<Texture>* textures, float switchTime, Vector2f position, Vector2u size)
		:SpriteObject(textures,switchTime,position,size), GameObject(position,size), AnimatedObject(textures,switchTime)
	{
		//cs.setOrigin(Vector2f((getSize().x / 2), (getSize().y / 2)));
	}
	/**
	* @brief update - Funkcja aktualizujaca pozycje gracza
	* @param moveVector - Wektor przemieszczenia
	**/
	void update(Vector2f moveVector);
	/**
	* @brief draw - Funkcja rysujaca pozycje gracza
	* @param window - Wskaznik na okno gry
	* @param alfa - Kat pod jakim ma zostac obrocona bitmapa
	**/
	void draw(RenderWindow* window,float alfa);
};
#endif // !player_h
