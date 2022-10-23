#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<map>
#include<set>
#ifndef engine_h
#define engine_h

using namespace sf;
using namespace std;

class Engine
{
public:
	Engine(RenderWindow* window);
	void changeGraphicMode(int width, int height,String title, Uint32 style);
	void closeGame();
	void clearScreen(Color color);
	void gameLoop();
	void eventRegister(int key, void (*function)(), bool hold);
	void handleAction(Event* event);
private:
	RenderWindow* window;
	Event event;
	map<int , void(*)()> keyToFuncMap;
	set<int> holdableKeys;
};
#endif