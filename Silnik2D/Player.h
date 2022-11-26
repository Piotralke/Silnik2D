#pragma once
#ifndef player_h
#define player_h
#include "SpriteObject.h"

class Player : public SpriteObject
{
public:
	Player(std::vector<Texture>* textures, float switchTime, Vector2f position, Vector2u size)
		:SpriteObject(textures,switchTime,position,size), GameObject(position,size), AnimatedObject(textures,switchTime)
	{
		
	}
	void update(Vector2f moveVector,float alfa);
	void draw(RenderWindow* window,float alfa);
};
#endif // !player_h
