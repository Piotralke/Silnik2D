/**
* @file LineSegment.h
* @brief Plik naglowkowy Line Segment
**/
#pragma once
#include "Point2D.h"
#include "PrimitiveRenderer.h"

#ifndef linesegment_h
#define linesegment_h

using namespace sf;
/**
* @class LineSegment
* @brief Klasa reprezentujaca linie
**/
class LineSegment : public ShapeObject
{
private:
	Point2D first;/*!<Wspolrzedne poczatku linii>*/
	Point2D second;/*!<Wspolrzedne konca linii>*/
public:
	/**
	* @brief LineSegment - Konstruktor z parametrami
	* @param first - Wspolrzedne poczatku linii
	* @param second - Wspolrzedne konca linii
	**/
	LineSegment(Point2D first, Point2D second);
	/**
	* @brief getFirst - Zwraca wspolrzedne poczatku linii
	**/
	Point2D getFirst();
	/**
	* @brief getSecond - Zwraca wspolrzedne konca linii
	**/
	Point2D getSecond();
	/**
	* @brief setFirst - Ustawia wspolrzedne poczatku linii
	* @param point -  Nowe wspolrzedne poczatku linii
	**/
	void setFirst(Point2D point);
	/**
	* @brief setSecond - Ustawia wspolrzedne konca linii
	* @param point - Nowe wspolrzedne konca linii
	**/
	void setSecond(Point2D point);
	/**
	* @brief draw - Funkcja umozliwiajaca rysowanie linii
	* @param mode - Wybor algorytmu do rysowania linii
	* @param pr - Wskaznik na klase PrimitiveRenderer
	* @param color - Kolor linii
	**/
	void draw(int mode, PrimitiveRenderer* pr, Color color);
	/**
	* @brief translate - Funkcja umozliwiajaca przesuwanie linii
	* @param vector - Wektor przemieszczenia
	**/
	void translate(Vector2f vector);
	/**
	* @brief rotate - Funkcja umozliwiajaca obracanie linii
	* @param point - Wspolrzedne punktu wobec ktorego ma wykonac obrot
	* @param alfa - Kat o jaki ma obrocic
	**/
	void rotate(Vector2f& point, float alfa);
	/**
	* @brief scale - Funkcja umozliwiajaca skalowanie linii
	* @param point - Wspolrzedne punktu wobec ktorego ma wykonac skalowanie
	* @param k - Wspolczynnik skalowania
	**/
	void scale(Vector2f& point, float k);
};

#endif
