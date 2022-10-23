#pragma once
#include "Engine.h"


void Engine::changeGraphicMode(RenderWindow &window,int width,int height,String title, Uint32 style )
{
	window.create(VideoMode(width, height), title, style);
}
void Engine::closeGame(RenderWindow& window) {
	window.close();
}
void Engine::clearScreen(RenderWindow &window, Color color)
{
	window.clear(color);
}
