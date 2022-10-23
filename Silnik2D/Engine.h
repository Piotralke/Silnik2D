#pragma once
#ifndef engine_h
#define engine_h
#include <SFML/Graphics.hpp>
using namespace sf;

class Engine
{
public:
	void changeGraphicMode(RenderWindow& window,int width, int height,String title, Uint32 style);
private:
};
#endif