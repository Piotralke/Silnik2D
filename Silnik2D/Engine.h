#pragma once
#include <SFML/Graphics.hpp>
#ifndef engine_h
#define engine_h

using namespace sf;

class Engine
{
public:
	void changeGraphicMode(RenderWindow& window,int width, int height,String title, Uint32 style);
	void closeGame(RenderWindow& window);
	void clearScreen(RenderWindow& window, Color color);
private:
};
#endif