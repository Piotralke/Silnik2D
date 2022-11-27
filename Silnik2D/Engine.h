/**
* @file Engine.h
* @brief Plik naglowkowy Engine.h
**/
#pragma once
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <time.h>
#include <ctime>
#include "RectangleObject.h"
#include "Player.h"
#include <Windows.h>
#include "BitmapHandler.h"
#ifndef engine_h
#define engine_h

using namespace sf;
using namespace std;

/*! To jest klasa enum bledow*/
enum Errors
{
	NO_FILE_ER,/*!<Blad braku pliku*/
	UNKNOWN_ER /*!<Nieznant blad*/
};
/**
* @class Engine
* @brief Klasa reprezentujaca silnik graficzny 2D
**/
class Engine
{
protected:
	static Engine* instance;/*!<Wskaznik na instancje klasy*/
public:
	/**
	* @brief Engine - Konstruktor klasy Engine
	* @param window - wskaznik na okno gry
	**/
	Engine(RenderWindow* window);
	/**
	* @brief changeResolution -  meotda zmieniajaca rozdzielczosc
	* @param width - szerokosc
	* @param height - wysokosc
	**/
	void changeResolution(int width, int height);
	/**
	* @brief enableFullscreen -  meotda przelaczajaca tryb wyswietlania
	* @param fullscreen - zmienna aktywujaca/wylaczajaca pelny ekran
	**/
	void enableFullscreen(bool fullscreen);
	/**
	* @brief enableFullscreen -  meotda zamykajaca gre
	**/
	void closeGame();
	/**
	* @brief clearScreen -  meotda wypelniajaca ekran danym kolorem
	* @param color - kolor
	**/
	void clearScreen(Color color);
	/**
	* @brief gameLoop -  glowna petla gry
	**/
	void gameLoop();
	/**
	* @brief keyboardEventRegister -  metoda przypisujaca klawisz do funkcji
	* @param key - przycisk na klawiaturze
	* @param function - wskaznik  na funkcje
	* @param hold - true - mozna trzymac przycisk do wywolania funkcji, false - nie mozna
	**/
	void keyboardEventRegister(int key, void (*function)(), bool hold);
	/**
	* @brief mouseEventRegister -  metoda przypisujaca przycisk myszy do funkcji
	* @param key - przycisk na myszcze
	* @param function - wskaznik  na funkcje
	* @param hold - true - mozna trzymac przycisk do wywolania funkcji, false - nie mozna
	**/
	void mouseEventRegister(int key, void (*function)(), bool hold);
	/**
	* @brief handleActionKeyboard - Wywolanie przypisanej funkcji pod klawisz o ile takowa jest
	* @param event - Wskaznik na zdarzenie
	**/
	void handleActionKeyboard(Event* event);
	/**
	* @brief handleActionKeyboard - Wywolanie przypisanej funkcji pod przycisk myszy o ile takowa jest
	* @param event - Wskaznik na zdarzenie
	**/
	void handleActionMouse(Event* event);
	/**
	* @brief setFPSLimit - Ustawia maksymalna wartosc FPS-ow
	* @param value - Maksymalna ilosc FPS-ow
	**/
	void setFPSLimit(unsigned int value);
	/**
	* @brief enableMouse - Czy synchronizacja pionowa wlaczona, czy wylaczona
	* @param value - Czy wlaczona/czy wylaczona
	**/
	void enableVSync(bool boolean);
	/**
	* @brief getInstance - pobranie instancji okna
	* @param window - okno gry
	**/
	static Engine* getInstance(RenderWindow* window);
	/** 
	* @brief getInstance - pobranie instancji
	**/
	static Engine* getInstance();
	/** 
	* @brief updateTimer - Aktualizacja czasomierza
	**/
	void updateTimer();
	/**
	* @brief enableMouse - Wlaczanie/wylaczanie myszki
	* @param value - Czy mysz wlaczona/czy wylaczona
	**/
	void enableMouse(bool value);
	/**
	* @brief enableKeyboard - Wlaczanie/wylaczenie klawiatury
	* @param value - Czy klawiatura wlaczona/czy wylaczona
	**/
	void enableKeyboard(bool value);
	/**
	* @brief reportError - metoda zglaszajacy blad
	* @param error - jaki blad
	* @param fileName - nazwa pliku w ktorym jest blad
	* @param line - linia bledu
	**/
	void reportError(Errors error, string fileName, int line);
	/**
	* @brief getWindow - zwraca okno
	**/
	RenderWindow* getWindow();
	std::vector<Point2D> pointVector;/*!<Wektor punktow*/
	
private:
	String Title = "Silnik2D"; /*!<Tytul*/
	RenderWindow* window; /*!<Instancja okna*/
	Time deltaTime; /*!<czas pomiedzy kolejnymi klatkami gry*/
	Clock clock; /*!<Instancja okna*/
	Event event; /*!<Dane zdarzenie np. klikniecie myszy*/
	map<int, void(*)()> keyboardToFuncMap; /*!<Mapa wydarzen dla klawiatury*/
	map<int, void(*)()> mouseToFuncMap; /*!<Mapa wydarzen dla myszki*/
	map<Errors, std::string> errorDesc; /*!<Mapa dla naszych bledow*/
	set<int> holdableKeys; /*!<Zbior przyciskow ktore mozna przytrzymac*/
	bool mouseOn = true; /*!<Parametr odpowiadajacy za wlaczenie obslugi myszki*/
	bool keyboardOn = true; /*!<Parametr odpowiadajacy za wlaczenie obslugi klawiatury*/
	int width; /*!<Szerokosc okna*/
	int height; /*!<Wysokosc okna*/
};
#endif