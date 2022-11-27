/**
* @file BitmapHandler.h
* @brief Plik naglowkowy BitmapHandler.h
**/
#pragma once
#ifndef bitmaphandler_h
#define bitmaphandler_h
#include "SFML/Graphics.hpp"
#include <map>
using namespace sf;

/**
* @class BitmapHandler
* @brief Klasa repozytorium bitmap
**/
class BitmapHandler
{
	std::map<std::string, Texture*> textureRepo;/*!<Mapa z repozytorium>*/
public:
	/**
	 * @brief Konstruktor 
	 */
	BitmapHandler();
	/**
	 * @brief Destruktor
	 */
	~BitmapHandler();

	/**
	* @brief deleteBitmap
	* @param name - Nazwa bitmapy
	**/
	void deleteBitmap(std::string name);
	/**
	* @brief deleteBitmap
	* @param name - Nazwa bitmapy
	* @param src - Sciezka do bitmapy
	**/
	void loadBitmap(std::string name, std::string src);
	/**
	* @brief deleteBitmap
	* @param name - Nazwa bitmapy
	* @param src - Sciezka do bitmapy
	**/
	void saveBitmap(std::string name, std::string src);
	/**
	* @brief deleteBitmap
	* @param name - Nazwa bitmapy
	* @param texture - Bitmapa
	**/
	void addBitmap(std::string name, Texture texture);
	/**
	* @brief deleteBitmap
	* @param name - Nazwa bitmapy
	**/
	Texture* getTexture(std::string name);

};

#endif // !bitmaphandler_h
