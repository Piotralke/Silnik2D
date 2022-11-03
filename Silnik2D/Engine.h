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
protected:
	static Engine* instance;
public:
	Engine(RenderWindow* window);
	void changeResolution(int width, int height);
	void enableFullscreen(bool fullscreen);
	void closeGame();
	void clearScreen(Color color);
	void gameLoop();
	void eventRegister(int key, void (*function)(), bool hold);
	void handleAction(Event* event);
	void setFPSLimit(unsigned int value);
	void enableVSync(bool boolean);
	static Engine* getInstance(RenderWindow* window);
	static Engine* getInstance();
private:
	
	String Title = "Silnik2D";
	RenderWindow* window;
	Event event;
	map<int , void(*)()> keyToFuncMap;
	set<int> holdableKeys;
};
#endif