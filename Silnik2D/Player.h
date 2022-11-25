#pragma once
#ifndef player_h
#define player_h
#include "RectangleObject.h"
#include "UpdatableObject.h"

class Player : public RectangleObject, public UpdatableObject
{
public:
	Player(Vector2f position, Vector2u size)
		:RectangleObject(position, size)
	{
		
	}
	void update(Vector2f moveVector,float alfa);
	//void draw(RenderWindow* window);
};
#endif // !player_h
