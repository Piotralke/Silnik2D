#include "GameObject.h"
void GameObject::setPosition(Vector2f& position)
{
	this->position = position;
}
Vector2f GameObject::getPosition()
{
	return position;
}
void GameObject::setSize(Vector2u size)
{
	this->size = size;
}
Vector2u GameObject::getSize()
{
	return size;
}