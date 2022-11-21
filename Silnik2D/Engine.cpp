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
    Point2D point(502, 500);
    Point2D point2(500, 735);
    Point2D point3(700, 700);
    Point2D point4(720, 500);
    LineSegment test(point3, point4);

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
        window->clear();
        //pr.drawRectangle(&point, 100, 100, Color::Red);
        //pr.drawRectangle(&point2, 200, 200, Color::Green);
        //pr.drawLine(&point, &point2, Color::Blue);
       // clearScreen(Color::Red);
        std::vector<Point2D> vector;
        vector.push_back(point);
        vector.push_back(point2);
        vector.push_back(point3);
        vector.push_back(point4);
        //pr.drawConvexShape(vector,sf::Color::Green);
        //pr.drawCircle(&point, 120.5, Color::Magenta);
        //test.draw(1, &pr, Color::White);
        pr.drawCircleByAlgorithm(&point, 70 ,Color::Red);
        pr.drawElipseByAlgorithm(&point, 100,50 ,Color::Cyan);

        pr.drawBrokenLine(vector, Color::White);
        pr.drawLineByAlgorithm(&point, &point3, Color::Green);
        //window.draw(shape);
        window->display();
    }
    closeGame();
}