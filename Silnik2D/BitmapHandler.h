#pragma once
#ifndef bitmaphandler_h
#define bitmaphandler_h
#include "SFML/Graphics.hpp"
#include <map>
using namespace sf;

class BitmapHandler
{
	std::map<std::string, Texture*> textureRepo;
public:

	BitmapHandler();
	~BitmapHandler();


	void deleteBitmap(std::string name);
	void loadBitmap(std::string name, std::string src);
	void saveBitmap(std::string name, std::string src);
	void addBitmap(std::string name, Texture texture);
	Texture* getTexture(std::string name);

};

#endif // !bitmaphandler_h
