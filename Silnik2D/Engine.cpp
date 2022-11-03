#pragma once
#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine(RenderWindow* window)
{
    this->window = window;
    this->instance = this;
}
Engine* Engine::getInstance(RenderWindow* window)
{
    if (instance == NULL)
    {
        instance = new Engine(window);
    }
    return instance;
}
Engine* Engine::getInstance()
{
    return instance;
}
void Engine::changeResolution(int width,int height)
{
    Vector2u vector = Vector2u(width, height);
    this->window->setSize(vector);
}
void Engine::enableFullscreen(bool fullscreen)
{
    if(fullscreen)
        this->window->create(sf::VideoMode::getFullscreenModes()[0],this->Title,sf::Style::Fullscreen);
    else
        this->window->create(sf::VideoMode::getFullscreenModes()[0], this->Title, sf::Style::Default);
}
void Engine::setFPSLimit(unsigned int value)
{
    this->window->setFramerateLimit(value); 
}
void Engine::enableVSync(bool boolean)
{
    this->window->setVerticalSyncEnabled(boolean);
}
void Engine::closeGame() 
{
	window->close();
}
void Engine::clearScreen(Color color)
{
	window->clear(color);
}

void Engine::eventRegister(int key, void (*function)(),bool hold)
{
    keyToFuncMap.insert(make_pair(key,function));
    if (hold)
    {
        holdableKeys.insert(key);
    }
}

void chuj()
{
    Engine* engine = Engine::getInstance();
    engine->enableFullscreen(true);
}
void chuj2()
{
    Engine* engine = Engine::getInstance();
    engine->enableFullscreen(false);
}

void Engine::handleAction(Event* event)
{
    if (keyToFuncMap.count(event->key.code))
    {
        auto action = keyToFuncMap.find(event->key.code)->second;
        action();
    }
}

void Engine::gameLoop()
{
    eventRegister(sf::Keyboard::F, &chuj, false);
    eventRegister(sf::Keyboard::W, &chuj2, false);
    while (window->isOpen())
    {
        
        if (window->pollEvent(event))
        {
            if (event.type == Event::MouseButtonPressed)
            {
                handleAction(&event);
            }
            else if (event.type == Event::KeyPressed)
            {
                handleAction(&event);
            }
            
        }
       // clearScreen(Color::Red);

        //window.clear();
        //window.draw(shape);
        window->display();
    }
}
