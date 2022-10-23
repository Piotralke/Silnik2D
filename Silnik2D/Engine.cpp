#pragma once
#include "Engine.h"

Engine::Engine(RenderWindow* window)
{
	this->window = window;
}

void Engine::changeGraphicMode(int width,int height,String title, Uint32 style )
{
	window->create(VideoMode(width, height), title, style);
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
    cout << "CHUJ CI W DUPE" << endl;
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

    eventRegister(Keyboard::K, &chuj, true);
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
