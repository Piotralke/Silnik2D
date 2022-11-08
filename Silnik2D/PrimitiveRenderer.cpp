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