/**
* @file AnimatedObject.h
* @brief Plik naglowkowy AnimatedObject.h
* 
**/
#pragma once
#include "GameObject.h"

/**
* @class AnimatedObject
* @brief Klasa animujaca dany obiekt gry
**/
class AnimatedObject: virtual public GameObject
{
public:
   
   /**
	* @brief AnimatedObject
	* Domyslny konstruktor klasy Animated Object
	**/
	AnimatedObject(){}
	/**
	* @brief AnimatedObject
	* @param textures - wektor tekstur 
	* @param switchTime - czas zmiany tekstury (czas animacji)
	* Konstruktor klasy AnimatedObject z parametrami
	**/
	AnimatedObject(std::vector<Texture>* textures,float switchTime)
	{
		this->switchTime = switchTime; 
		this->textures = textures;
		this->totalTime = 0.0;
	}
	/**
	* @brief animate - metoda animujaca dany obiekt
	* @param deltaTime - czas pomiedzy kolejnymi klatkami gry
	**/
	virtual void animate(float deltaTime);
protected:
	float switchTime;/*!<Czas zmiany animacji>*/
	float totalTime;/*!<Calkowity czas animacji>*/
	int index;/*!<Index danej tekstury w wektorze>*/
	std::vector<Texture>* textures;/*!<Wektor Tekstur>*/
};
