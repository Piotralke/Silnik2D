#include "LineSegment.h"

LineSegment::LineSegment(Point2D first, Point2D second)
{
	this->first = first;
	this->second = second;
}
Point2D LineSegment::getFirst() 
{
	return first;
}
Point2D LineSegment::getSecond()
{
	return second;
}
void LineSegment::setFirst(Point2D point)
{
	this->first = point;
}
void LineSegment::setSecond(Point2D point)
{
	this->second = point;
}
void LineSegment::draw(int mode, PrimitiveRenderer* pr, Color color) 
{
	if (mode == 1) // tu bedzie pokazanie defaultowe, mozliwe ze sie zmieni jak uzyjemy algorytmu
	{
		pr->drawLine(&first, &second, color);
	}
	else if (mode == 2) //tu bedzie pokazanie algorytmem
	{
		pr->drawLineByAlgorithm(&first, &second, color);
	}
}
void LineSegment::translate(Vector2f vector)
{

		Vector2f newPositionFirst = Vector2f(first.getPosition()+vector);
		Vector2f newPositionSecond = Vector2f(second.getPosition()+vector);
		first.setPosition(newPositionFirst);
		second.setPosition(newPositionSecond);
}
void LineSegment::rotate(Vector2f& point, float alfa)
{
	float x = point.x;
	float y = point.y;

	Vector2f newPositionFirst = Vector2f(x + (first.getX()-x)*cos(alfa)-(first.getY()-y)*sin(alfa),
		y+(first.getX()-x)*sin(alfa)+(first.getY()-y)*cos(alfa));
	Vector2f newPositionSecond = Vector2f(x + (second.getX() - x) * cos(alfa) - (second.getY() - y) * sin(alfa),
		y + (second.getX() - x) * sin(alfa) + (second.getY() - y) * cos(alfa));
	first.setPosition(newPositionFirst);
	second.setPosition(newPositionSecond);
}
void LineSegment::scale(Vector2f& point, float k)
{
	
		float x = point.x;
		float y = point.y;

		Vector2f newPositionFirst = Vector2f(first.getX() * k + (1 - k) * x, first.getY() * k + (1 - k) * y);
		Vector2f newPositionSecond = Vector2f(second.getX() * k + (1 - k) * x, second.getY() * k + (1 - k) * y);
		//Vector2f newPosition = Vector2f(position.x * k + (1 - k) * point.x, position.y * k + (1 - k) * point.y);
		first.setPosition(newPositionFirst);
		second.setPosition(newPositionSecond);
	
}