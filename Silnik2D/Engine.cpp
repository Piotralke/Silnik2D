#pragma once
#pragma warning(disable : 4996)
#include "Engine.h"


Engine* Engine::instance = nullptr;

Engine::Engine(RenderWindow* window)
{
    this->window = window;
    this->instance = this;
    this->width = window->getSize().x;
    this->height = window->getSize().y;
    this->errorDesc.insert(make_pair(NO_FILE_ER, "Nie znaleziono pliku!"));
    this->errorDesc.insert(make_pair(UNKNOWN_ER, "Nieznany blad"));
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
    this->width = width;
    this->height = height;
}
void Engine::enableFullscreen(bool fullscreen)
{
    if(fullscreen)
        this->window->create(sf::VideoMode::getFullscreenModes()[0],this->Title,sf::Style::Fullscreen);
    else
    {
        this->window->create(sf::VideoMode::getFullscreenModes()[0], this->Title, sf::Style::Default);
        changeResolution(this->width, this->height);
    }
        
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
void Engine::enableMouse(bool value)
{
    this->mouseOn = value;
}
void Engine::enableKeyboard(bool value)
{
    this->keyboardOn = value;
}
void Engine::updateTimer()
{
    this->deltaTime = this->clock.restart();
}
void Engine::reportError(Errors error, string fileName, int line)
{

    ofstream file("error_logs.txt", ios_base::app);
    time_t test = time(0);
    char time_and_date[32];
    tm* localTime;
    localTime = localtime(&test);
    strftime(time_and_date, 32, "%d-%m-%Y-%H:%M:%S", localTime);
    file << "ERROR:" << error << " | Description: "<< errorDesc.find(error)->second << " | At: ["<< 
        time_and_date << "] | In file: " << fileName << " | At line:" << line << endl;
    file.close();
}
void Engine::gameLoop()
{
    Point2D point(50, 50);
    PrimitiveRenderer pr(window);
    eventRegister(sf::Keyboard::F, &chuj, false);
    eventRegister(sf::Keyboard::W, &chuj2, false);
   // reportError(UNKNOWN_ER, __FILE__, __LINE__);
    while (window->isOpen())
    {
        updateTimer();
        if (window->pollEvent(event))
        {
            if (event.type == Event::MouseButtonPressed && mouseOn)
            {
                handleAction(&event);
            }
            else if (event.type == Event::KeyPressed && keyboardOn)
            {
                handleAction(&event);
            }
            
        }
        point.draw(&pr,sf::Color::Magenta);
       // clearScreen(Color::Red);

        //window.clear();
        //window.draw(shape);
        window->display();
    }
    closeGame();
}
