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
	GameObject() {}
	GameObject(Vector2f position, Vector2u size)
	{
		this->position = position;
		this->size = size;
		points.push_back(position);
		points.push_back(Vector2f(position.x + size.x, position.y));
		points.push_back(Vector2f(position.x + size.x, position.y + size.y));
		points.push_back(Vector2f(position.x, position.y + size.y));
	}
	std::vector<Vector2f> points;
	virtual void setPosition(Vector2f& position);
	virtual Vector2f getPosition();
	virtual void setSize(Vector2u size);
	virtual Vector2u getSize();
};
#endif // gameobject_h

