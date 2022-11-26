#include "Transformable.h"

void TransformableObject::translate(Vector2f vector)
{
	if (vector.x != 0 || vector.y != 0)
	{
		Vector2f newPosition = Vector2f(position.x + vector.x, position.y - vector.y);
		this->setPosition(newPosition);
		for (int i = 0; i < this->points.size(); i++)
		{
			this->points[i].x += vector.x;
			this->points[i].y -= vector.y;

		}
	}
}
void TransformableObject::rotate(Vector2f& point, float alfa)
{
	float x = point.x;
	float y = point.y;
	for (int i = 0; i < this->points.size(); i++)
	{
		Vector2f position = Vector2f(this->points[i].x, this->points[i].y);
		Vector2f newPosition = Vector2f(x + (position.x - x) * cos(alfa) - (position.y - y) * sin(alfa),
			y + (position.x - x) * sin(alfa) + (position.y - y) * cos(alfa));
		this->points[i].x = newPosition.x;
		this->points[i].y = newPosition.y;
	}
}
void TransformableObject::scale(Vector2f& point, float k)
{
	for (int i = 0; i < this->points.size(); i++)
	{
		Vector2f position = Vector2f(this->points[i].x, this->points[i].y);
		Vector2f newPosition = Vector2f(position.x * k + (1 - k) * point.x, position.y * k + (1 - k) * point.y);
		this->points[i].x = newPosition.x;
		this->points[i].y = newPosition.y;
	}
}