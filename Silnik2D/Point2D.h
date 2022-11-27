/**
* @file Point2D.h
* @brief Plik naglowkowy Point2D.h
**/
#pragma once
#include "ShapeObject.h"

#ifndef point2d_h
#define point2d_h
using namespace sf;

/**
* @class Point2D
* @brief Klasa reprezentujaca punkty
**/
class Point2D : public ShapeObject 
{
public:
	/**
	* @brief Point2D
	* @param x - wspolrzedna x danego punktu
	* @param y - wspolrzedna y danego punktu
	* Konstruktor klasy Point2D z parametrami
	**/
	Point2D(float x, float y);
	/**
	* @brief Point2D - Domyslny konstruktor klasy Point2D
	**/
	Point2D();
	/**
	* @brief Point2D - Konstruktor klasy Point2D z parametrami
	* @param point - wektor wspolrzednych danego punktu
	**/
	Point2D(Vector2f point); 
	/**
	* @brief getX - Pobranie wspolrzednej x
	**/
	float getX();
	/**
	* @brief getY - Pobranie wspolrzednej y
	**/
	float getY();
	/**
	* @brief setX - Ustawienie wspolrzednej x
	* @param x - wspolrzedna x
	**/
	void setX(float x);
	/**
	* @brief setY - Ustawienie wspolrzednej y
	* @param y - wspolrzedna y
	**/
	void setY(float y);
	/**
	* @brief getVector - pobranie wektora wspolrzednych x i y
	**/
	Vector2f getVector();
	/**
	* @brief getPoint - pobranie punktu ze wspolrzednymi x i y
	**/
	Point2D getPoint();
	/**
	* @brief draw - abstrakcyjna metoda rysowania na ekranie z danym kolorem
	* @param window - okno na ktorym ma byc narysowane
	* @param color - kolor
	**/
	virtual void draw(RenderWindow* window, Color color);
};

#endif