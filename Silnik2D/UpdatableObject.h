/**
* @file UpdatableObject.h
* @brief Plik naglowkowy UpdatableObject.h
* 
**/
#pragma once
#ifndef updatableobject_h
#define updatableobject_h
#include"GameObject.h"
/**
* @class UpdatableObject
* @brief Klasa reprezentujaca obiekt, ktory moze byc w jakikolwiek sposob aktualizowany
**/
class UpdatableObject : virtual public GameObject
{
public:
	/**
	* @brief update - metoda aktualizujaca dany obiekt
	**/
	void update();
};

#endif // !updatableobject_h
