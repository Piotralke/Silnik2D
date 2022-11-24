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
	virtual void setPosition(Vector2f& position);
	virtual Vector2f getPosition();
	virtual void setSize(Vector2u size);
	virtual Vector2u getSize();
};
#endif // gameobject_h

