#include "AnimatedObject.h"
#include <iostream>

void AnimatedObject::animate(float deltaTime)
{
		totalTime += deltaTime;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			if (index == textures->size() - 1)
				index = 0;
			else
				index++;
		}	
}