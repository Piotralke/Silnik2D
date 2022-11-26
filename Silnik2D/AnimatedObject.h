#pragma once
#include "GameObject.h"


class AnimatedObject: virtual public GameObject
{
public:
	AnimatedObject(){}
	AnimatedObject(std::vector<Texture>* textures,float switchTime)
	{
		this->switchTime = switchTime;
		this->textures = textures;
		this->totalTime = 0.0;
	}
	virtual void animate(float deltaTime);
protected:
	float switchTime;
	float totalTime;
	int index;
	std::vector<Texture>* textures;
};
