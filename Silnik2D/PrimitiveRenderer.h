#pragma warning(disable : 4996)
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
/**
* @file PrimitiveRenderer.h
* @brief Plik naglowkowy PrimitiveRenderer.h
**/
#include "Point2D.h"

#ifndef primitiverenderer_h
#define primitiverenderer_h

using namespace sf;
/**
* @class PrimitiveRenderer
* @brief Klasa odpowiedzialna za renderowanie prymitywow
**/
class PrimitiveRenderer
{
private:
	RenderWindow* window;/*!<Wskaznik na okno gry>*/
public:
	/**
	* @brief PrimitiveRenderer - Konstruktor klasy
	* @param window - Wskaznik na okno gry
	**/
	PrimitiveRenderer(RenderWindow* window);
	/**
	* @brief drawPoint - metoda rysujaca punkt
	* @param point - punkt
	* @param color - kolor
	**/
	void drawPoint(Point2D* point, Color color);
	/**
	* @brief drawRectangle - metoda rysujaca prostokat
	* @param point - punkt poczatkowy
	* @param width - szerokosc
	* @param height - wysokosc
	* @param color - kolor
	**/
	void drawRectangle(Point2D* point,int width, int height, Color color);
	/**
	* @brief drawFilledRectangle - metoda rysujaca wypelniony prostokat
	* @param point - punkt poczatkowy
	* @param width - szerokosc
	* @param height - wysokosc
	* @param color - kolor
	**/
	void drawFilledRectangle(Point2D* point,int width, int height, Color color);
	/**
	* @brief drawSquare - metoda rysujaca kwadrat
	* @param point - punkt poczatkowy
	* @param x - dlugosc boku
	* @param color - kolor
	**/
	void drawSquare(Point2D* point,int x, Color color);
	/**
	* @brief drawFilledSquare - metoda rysujaca wypelniony kwadrat
	* @param point - punkt poczatkowy
	* @param x - dlugosc boku
	* @param color - kolor
	**/
	void drawFilledSquare(Point2D* point,int x, Color color);
	/**
	* @brief drawLine - metoda rysujaca linie
	* @param point1 - punkt poczatkowy
	* @param point2 - punkt koncowy
	* @param color - kolor
	**/
	void drawLine(Point2D* point1, Point2D* point2, Color color);
	/**
	* @brief drawLineByAlgorithm - metoda rysujaca linie algorytmem przyrostowym
	* @param point1 - punkt poczatkowy
	* @param point2 - punkt koncowy
	* @param color - kolor
	**/
	void drawLineByAlgorithm(Point2D* point1, Point2D* point2, Color color);
	/**
	* @brief drawConvexShape - metoda rysujaca wielokat
	* @param vec - wektor punktow wielokata
	* @param color - kolor
	**/
	void drawConvexShape(std::vector<Point2D> vec, Color color);
	/**
	* @brief drawCircle - metoda rysujaca okrag
	* @param point - punkt poczatkowy
	* @param radius - promien
	* @param color - kolor
	**/
	void drawCircle(Point2D* point, float radius, Color color);
	/**
	* @brief drawFilledCircle - metoda rysujaca wypelniony okrag
	* @param point - punkt poczatkowy
	* @param radius - promien
	* @param color - kolor
	**/
	void drawFilledCircle(Point2D* point, float radius, Color color);
	/**
	* @brief drawCircleByAlgorithm - metoda rysujaca okrag algorytmem
	* @param point - punkt poczatkowy
	* @param radius - promien
	* @param color - kolor
	**/
	void drawCircleByAlgorithm(Point2D* point, float radius, Color color);
	/**
	* @brief drawElipseByAlgorithm - metoda rysujaca elipse algorytmem
	* @param point - punkt poczatkowy
	* @param radiusX - promien X
	* @param radiusY - promien Y
	* @param color - kolor
	**/
	void drawElipseByAlgorithm(Point2D* point, float radiusX, float radiusY, Color color);
	/**
	* @brief drawBrokenLine - Metoda rysujaca otwarta lub zamknieta linie 
	* @param vec - wektor punktow
	* @param color - kolor 
	* @param closed - czy linia ma byc zamknieta czy otwarta
	**/
	void drawBrokenLine(std::vector<Point2D> vec, Color color, bool closed);
	/**
	* @brief floodFill - algorytm wypelniania kolorem "floodFill"
	* @param point punkt poczatkowy
	* @param color - kolor 
	* @param backgroundColor - kolor tla
	**/
	void floodFill(Point2D* point, Color color, Color backgroundColor);
	/**
	* @brief boundryFill - algorytm wypelniania kolorem "boundryFill"
	* @param point - punkt poczatkowy
	* @param fillcolor - kolor wypelnienia
	* @param boundryColor - kolor obramowania
	**/
	void boundryFill(Point2D* point, Color fillColor, Color boundryColor);
};

#endif