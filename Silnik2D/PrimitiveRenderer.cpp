#include "PrimitiveRenderer.h"
#include <stack>

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
void PrimitiveRenderer::drawFilledRectangle(Point2D* point, int width, int height, Color color)
{
	RectangleShape shape;
	shape.setPosition(point->getVector());
	shape.setSize(Vector2f(width, height));
	shape.setOutlineThickness(1);
	shape.setFillColor(color);
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
void PrimitiveRenderer::drawFilledSquare(Point2D* point, int x, Color color)
{
	RectangleShape shape;
	shape.setPosition(point->getVector());
	shape.setSize(Vector2f(x, x));
	shape.setOutlineThickness(1);
	shape.setFillColor(color);
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
void PrimitiveRenderer::drawLineByAlgorithm(Point2D* point1, Point2D* point2, Color color)
{
	float minX = std::min(point1->getX(), point2->getX());
	float maxX = std::max(point1->getX(), point2->getX());
	float minY = std::min(point1->getY(), point2->getY());
	float maxY = std::max(point1->getY(), point2->getY());
	float deltaX = maxX-minX;
	float deltaY = maxY-minY;
	float m = deltaY/deltaX;
	if (abs(m) > 1)
	{
		m = deltaX / deltaY;
		for (float i = minY; i < maxY; i++)
		{
			float x = m * (i - minY) + minX;
			Point2D p = Point2D(std::round(x), i);
			drawPoint(&p, color);
		}
	}
	else
	{
		for (float i = minX; i < maxX; i++)
		{
			float y = m * (i - minX) + minY;
			Point2D p = Point2D(i, std::round(y));
			drawPoint(&p,color);
		}
	}

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
void PrimitiveRenderer::drawCircleByAlgorithm(Point2D* point, float radius, Color color)
{
	float x = point->getX();
	float y = point->getY();
	float step = (float)1 / radius;
	for (float i = 0; i < M_PI / 2; i += step)
	{
		float drawX = radius * cos(i);
		float drawY = radius * sin(i);
		Point2D p1 = Point2D(x + drawX, y + drawY);
		Point2D p2 = Point2D(x + drawX, y - drawY);
		Point2D p3 = Point2D(x - drawX, y + drawY);
		Point2D p4 = Point2D(x - drawX, y - drawY);
		drawPoint(&p1, color);
		drawPoint(&p2, color);
		drawPoint(&p3, color);
		drawPoint(&p4, color);
	}

}
void PrimitiveRenderer::drawElipseByAlgorithm(Point2D* point, float radiusX,float radiusY, Color color)
{
	float x = point->getX();
	float y = point->getY();
	float maxR = std::max(radiusX, radiusY);
	float step = (float)1 / maxR;
	for (float i = 0; i < M_PI / 2; i += step)
	{
		float drawX = radiusX * cos(i);
		float drawY = radiusY * sin(i);
		Point2D p1 = Point2D(x + drawX, y + drawY);
		Point2D p2 = Point2D(x + drawX, y - drawY);
		Point2D p3 = Point2D(x - drawX, y + drawY);
		Point2D p4 = Point2D(x - drawX, y - drawY);
		drawPoint(&p1, color);
		drawPoint(&p2, color);
		drawPoint(&p3, color);
		drawPoint(&p4, color);
	}

}
void PrimitiveRenderer::drawCircle(Point2D* point, float radius, Color color)
{
	sf::CircleShape shape(radius);

	shape.setPosition(point->getX() - radius, point->getY() - radius);
	shape.setOutlineThickness(1);
	shape.setFillColor(Color(0, 0, 0, 0));
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawFilledCircle(Point2D* point, float radius, Color color)
{
	sf::CircleShape shape(radius);

	shape.setPosition(point->getX() - radius, point->getY() - radius);
	shape.setOutlineThickness(1);
	shape.setFillColor(color);
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawBrokenLine(std::vector<Point2D> vec, Color color)
{
	for (int i = 1; i < vec.size(); i++)
		PrimitiveRenderer::drawLine(&vec[i-1], &vec[i], color);
	PrimitiveRenderer::drawLine(&vec[vec.size()-1], &vec[0], color);
}
void PrimitiveRenderer::floodFill(Point2D* point, Color fillColor, Color backgroundColor)
{
	Texture texture;
	texture.create(window->getSize().x, window->getSize().y);
	texture.update(*window);
	Image image = texture.copyToImage();
	auto color = image.getPixel(point->getX(), point->getY());
	Point2D p = Point2D(point->getVector());
	std::stack<Point2D> stack;
	stack.push(p);
	while (!stack.empty())
	{

		p.setX(stack.top().getX());
		p.setY(stack.top().getY());
		stack.pop();
		if (image.getPixel(p.getX(), p.getY()) == fillColor)
			continue;
		if (image.getPixel(p.getX(), p.getY()) != backgroundColor)
			continue;
		drawPoint(&p, fillColor);
		image.setPixel(p.getX(), p.getY(), fillColor);

		if (p.getY() - 1 > 0)
			stack.push(Point2D(p.getX(), p.getY() - 1));

		if (p.getY() + 1 < window->getSize().y)
			stack.push(Point2D(p.getX(), p.getY() + 1));

		if (p.getX() - 1 > 0)
			stack.push(Point2D(p.getX() - 1, p.getY()));

		if (p.getX() + 1 < window->getSize().x)
			stack.push(Point2D(p.getX() + 1, p.getY()));

	}
}
void PrimitiveRenderer::boundryFill(Point2D* point, Color fillColor, Color boundryColor)
{
	Texture texture;
	texture.create(window->getSize().x, window->getSize().y);
	texture.update(*window);
	Image image = texture.copyToImage();
	Point2D p = Point2D(point->getVector());
	std::stack<Point2D> stack;
	stack.push(p);
	while (!stack.empty())
	{

		p.setX(stack.top().getX());
		p.setY(stack.top().getY());
		stack.pop();
		if (image.getPixel(p.getX(), p.getY()) == fillColor)
			continue;
		if (image.getPixel(p.getX(), p.getY()) == boundryColor)
			continue;
		drawPoint(&p, fillColor);
		image.setPixel(p.getX(), p.getY(), fillColor);

		if (p.getY() - 1 > 0)
			stack.push(Point2D(p.getX(), p.getY() - 1));

		if (p.getY() + 1 < window->getSize().y)
			stack.push(Point2D(p.getX(), p.getY() + 1));

		if (p.getX() - 1 > 0)
			stack.push(Point2D(p.getX() - 1, p.getY()));

		if (p.getX() + 1 < window->getSize().x)
			stack.push(Point2D(p.getX() + 1, p.getY()));

	}
}