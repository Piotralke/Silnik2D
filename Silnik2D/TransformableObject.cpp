#include "Transformable.h"

void TransformableObject::translate(Vector2f vector)
{
	Vector2f position = this->getPosition();
	Vector2f newPosition = Vector2f(position.x + vector.x, position.y - vector.y);
	this->setPosition(newPosition);
}
void TransformableObject::rotate(Vector2f& point, float alfa)
{
	Vector2f position = this->getPosition();
	float x = point.x;
	float y = point.y;
	Vector2f newPosition = Vector2f(x + (position.x - x) * cos(alfa) - (position.y - y) * sin(alfa),
		y + (position.x - x) * sin(alfa) + (position.y - y) * cos(alfa));
	this->setPosition(newPosition);
}
void TransformableObject::scale(float k)
{
	Vector2f position = this->getPosition();
	Vector2f newPosition = Vector2f(position.x * k, position.y * k);
	this->setPosition(newPosition);
}

void TransformableObject::scale(Vector2f& point, float k)
{
	Vector2f position = this->getPosition();
	Vector2f newPosition = Vector2f(position.x * k + (1 - k) * point.x, position.y * k + (1 - k) * point.y);
	this->setPosition(newPosition);
}