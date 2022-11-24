#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}
Point2D::Point2D(Vector2f point)
{
	this->position.x = point.x;
	this->position.y = point.y;
}
Point2D::Point2D()
{
	this->position.x = 0;
	this->position.y = 0;
}
float Point2D::getX()
{
	return this->position.x;
}
float Point2D::getY()
{
	return this->position.y;
}
void Point2D::setX(float x)
{
	this->position.x = x;
}
void Point2D::setY(float y)
{
	this->position.y = y;
}
Vector2f Point2D::getVector()
{
	return Vector2f(this->position.x,this->position.y);
}
Point2D Point2D::getPoint()
{
	return Point2D(this->position.x, this->position.y);
}
void Point2D::draw(RenderWindow* window, Color color)
{
	sf::Vertex vertex(this->getVector(), color);
	window->draw(&vertex, 1, sf::Points);
}
