#pragma once
#include <SFML/Graphics.hpp>
#ifndef gameobject_h
#define gameobject_h
using namespace sf;
class GameObject
{
protected:
	Vector2f position;
	Vector2u size;
public:
	void setPosition(Vector2f& position);
	Vector2f getPosition();
	void setSize(Vector2u size);
	Vector2u getSize();
};
#endif // gameobject_h

