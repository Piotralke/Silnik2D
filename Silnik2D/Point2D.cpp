#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}
Point2D::Point2D(Vector2f point)
{
	this->x = point.x;
	this->y = point.y;
}
float Point2D::getX()
{
	return this->x;
}
float Point2D::getY()
{
	return this->y;
}
void Point2D::setX(float x)
{
	this->x = x;
}
void Point2D::setY(float y)
{
	this->y = y;
}
Vector2f Point2D::getVector()
{
	return Vector2f(this->x,this->y);
}
Point2D Point2D::getPoint()
{
	return Point2D(this->x, this->y);
}
