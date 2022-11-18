#pragma once
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<map>
#include<set>
#include<fstream>
#include<time.h>
#include<ctime>
#ifndef engine_h
#define engine_h

using namespace sf;
using namespace std;


enum Errors
{
	NO_FILE_ER,
	UNKNOWN_ER
};
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
	void updateTimer();
	void enableMouse(bool value);
	void enableKeyboard(bool value);
	void reportError(Errors error, string fileName, int line);
	
private:
	String Title = "Silnik2D";
	RenderWindow* window;
	Time deltaTime;
	Clock clock;
	Event event;
	map<int, void(*)()> keyToFuncMap;
	map<Errors, std::string> errorDesc;
	set<int> holdableKeys;
	bool mouseOn = true;
	bool keyboardOn = true;
	int width;
	int height;
};
#endif