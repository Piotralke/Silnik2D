#include "BitmapHandler.h"

BitmapHandler::BitmapHandler()
{
}

BitmapHandler::~BitmapHandler()
{
	std::map<std::string, Texture*>::iterator it;
	for (it = textureRepo.begin(); it != textureRepo.end(); it++)
	{
		delete it->second;
	}
}

void BitmapHandler::deleteBitmap(std::string name)
{
	std::map<std::string, Texture*>::iterator it;
	it = textureRepo.find(name);
	if (it == textureRepo.end())
	{
		return;
	}
	delete textureRepo.find(name)->second;
	textureRepo.erase(name);
}

void BitmapHandler::loadBitmap(std::string name, std::string src)
{
	Texture* tmp = new Texture();
	tmp->loadFromFile(src);
	textureRepo.insert(std::pair<std::string, Texture*>(name, tmp));
}

void BitmapHandler::saveBitmap(std::string name, std::string src)
{
	std::map<std::string, Texture*>::iterator it;
	it = textureRepo.find(name);
	if (it == textureRepo.end())
	{
		return;
	}
	textureRepo.find(name)->second->copyToImage().saveToFile(src);
}

void BitmapHandler::addBitmap(std::string name, Texture texture)
{
	Texture* tmp = new Texture(texture);
	textureRepo.insert(std::pair<std::string, Texture*>(name, tmp));
}

Texture* BitmapHandler::getTexture(std::string name)
{
	std::map<std::string, Texture*>::iterator it;
	it = textureRepo.find(name);
	if (it == textureRepo.end())
	{
		return nullptr;
	}
	return textureRepo.find(name)->second;
}