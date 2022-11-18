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

	}
}