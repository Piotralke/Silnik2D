#include "PrimitiveRenderer.h"

PrimitiveRenderer::PrimitiveRenderer(RenderWindow* window)
{
	this->window = window;
}
void PrimitiveRenderer::drawPoint(Point2D* point,Color color)
{
	sf::Vertex vertex(point->getVector(), color);
	this->window->draw(&vertex,1,sf::Points);
}
void PrimitiveRenderer::drawRectangle(Point2D* point, int width, int height, Color color)
{
	RectangleShape shape;
	shape.setPosition(point->getVector());
	shape.setSize(Vector2f(width, height));
	shape.setOutlineThickness(1);
	shape.setFillColor(Color(0,0,0,0));
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawSquare(Point2D* point, int x, Color color)
{
	RectangleShape shape;
	shape.setPosition(point->getVector());
	shape.setSize(Vector2f(x, x));
	shape.setOutlineThickness(1);
	shape.setFillColor(Color(0, 0, 0, 0));
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawLine(Point2D* point1, Point2D* point2, Color color)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(point1->getVector())),
		sf::Vertex(sf::Vector2f(point2->getVector()))
	};
	window->draw(line,2,sf::Lines);
}
void PrimitiveRenderer::drawConvexShape(std::vector<Point2D> vec, Color color)
{
	sf::ConvexShape convex;
	convex.setPointCount(vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		convex.setPoint(i, sf::Vector2f(vec[i].getVector()));
	}
	convex.setOutlineThickness(1);
	convex.setOutlineColor(color);
	convex.setFillColor(Color(0, 0, 0, 0));
	window->draw(convex);
}
void PrimitiveRenderer::drawCircle(Point2D* point, float radius, Color color)
{
	sf::CircleShape shape(radius);

	shape.setPosition(point->getX()-radius,point->getY()-radius);
	shape.setOutlineThickness(1);
	shape.setFillColor(Color(0, 0, 0, 0));
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawBrokenLine(std::vector<Point2D> vec, Color color)
{
	for (int i = 1; i < vec.size(); i++)
		PrimitiveRenderer::drawLine(&vec[i-1], &vec[i], color);
	PrimitiveRenderer::drawLine(&vec[vec.size()-1], &vec[0], color);
}