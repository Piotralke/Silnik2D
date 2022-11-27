#pragma once
#pragma warning(disable : 4996)
#include "Engine.h"

Vector2f moveVector(0, 0);
bool moving;
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

void Engine::keyboardEventRegister(int key, void (*function)(),bool hold)
{
	keyboardToFuncMap.insert(make_pair(key,function));
    if (hold)
    {
        holdableKeys.insert(key);
    }
}
void Engine::mouseEventRegister(int key, void (*function)(), bool hold)
{
	mouseToFuncMap.insert(make_pair(key, function));
	if (hold)
	{
		holdableKeys.insert(key);
	}
}
void gora()
{
    moveVector.y = 5;

}
void dol()
{
    moveVector.y = -5;

}
void lewo()
{
    moveVector.x = -5;

}
void prawo()
{
    moveVector.x = 5;

}
void makeCircle()
{
    Engine* engine = Engine::getInstance();
    RenderWindow* window = engine->getWindow();
    PrimitiveRenderer pr(window);
    Point2D point(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
    engine->pointVector.push_back(point);
}
void setFullscreen()
{
    Engine* engine = Engine::getInstance();
    engine->enableFullscreen(true);
}
void setWindowed()
{
    Engine* engine = Engine::getInstance();
    engine->enableFullscreen(false);
}

void Engine::handleActionKeyboard(Event* event)
{
    if (keyboardToFuncMap.count(event->key.code))
    {
        auto action = keyboardToFuncMap.find(event->key.code)->second;
        action();
    }
}
void Engine::handleActionMouse(Event* event)
{
	if (mouseToFuncMap.count(event->key.code))
	{
		auto action = mouseToFuncMap.find(event->key.code)->second;
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
    Point2D pointFill(480, 470);
    Point2D pointFillBoundry(530, 540);
    LineSegment test(point3, point4);
    Vector2f v1(50, 50);
    Vector2f v2(50, 100);
    Vector2f v3(100, 100);
    Vector2f v4(100,50 );

    BitmapHandler bitmapHandler;
    bitmapHandler.loadBitmap("1", "1.png");
    bitmapHandler.loadBitmap("2", "2.png");
    bitmapHandler.loadBitmap("3", "3.png");
    bitmapHandler.loadBitmap("4", "4.png");
    bitmapHandler.loadBitmap("5", "5.png");
    bitmapHandler.loadBitmap("6", "6.png");
    bitmapHandler.loadBitmap("background", "background.png");
    std::vector<Texture> playerAnimation;
    for (int i = 0; i < 6; i++)
    {
        String tmp = std::to_string(i+1); 
        playerAnimation.push_back(*bitmapHandler.getTexture(tmp));
    }
    Vector2f position(500, 500);
    Vector2u playersize(100, 100);
    Player player(&playerAnimation, 0.5,position, playersize);

    PrimitiveRenderer pr(window);
	keyboardEventRegister(sf::Keyboard::W, &gora, true);
	keyboardEventRegister(sf::Keyboard::A, &lewo, true);
	keyboardEventRegister(sf::Keyboard::S, &dol, true);
	keyboardEventRegister(sf::Keyboard::D, &prawo, true);
	keyboardEventRegister(sf::Keyboard::F, &setFullscreen, false);
	keyboardEventRegister(sf::Keyboard::G, &setWindowed, false);
    mouseEventRegister(sf::Mouse::Left, &makeCircle, false);

   // reportError(UNKNOWN_ER, __FILE__, __LINE__);
    //test.scale(5);
    std::vector<Vector2f> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    vec.push_back(v4);
    Vector2u size(50, 50);
    Vector2f currentMousePos;
    Clock clock;
    float deltaTime;
    float mainRotation = 0;
    BitmapObject background(Vector2f(0, 0), Vector2u(width,height), bitmapHandler.getTexture("background"));
    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        moveVector = Vector2f(0, 0);
        float alfa = 0;
		float beta = 0;
        currentMousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        {

            Vector2f rotVec = Vector2f(player.cs.getOrigin().x, player.cs.getOrigin().y);

			Vector2f rotVec2 = Vector2f((player.cs.getOrigin().x + player.getSize().x)/2, (player.cs.getOrigin().y));

            if (rotVec2.x - rotVec.x != 0 && (currentMousePos.x - rotVec.x) != 0)
            {
				alfa = atan2((currentMousePos.y - rotVec.y), (currentMousePos.x - rotVec.x)); //-atan((xA - a2) / (1 + xA * a2));
				alfa *= (180 / M_PI);
            }
                
        }
        //moving = false;
        updateTimer();
        if (window->pollEvent(event))
        {
            if (event.type == Event::MouseButtonPressed && mouseOn)
            {
                handleActionMouse(&event);
            }
            else if (event.type == Event::KeyPressed && keyboardOn)
            {
                handleActionKeyboard(&event);
            }
            else if (event.type == Event::Closed)
            {
                window->close();
            }
            
        }
       // std::cout << previousMousePos.x << ", " << previousMousePos.y << std::endl;
        player.update(moveVector);
        player.animate(deltaTime);
        window->clear();
        background.draw(window);
        pr.drawFilledRectangle(&point, 100, 100, Color::Red);
        for (int i = 0; i < pointVector.size(); i++)
        {
            pr.drawFilledCircle(&pointVector.at(i), 10.0, Color::Cyan);
        }
        player.draw(window, alfa);
        //pr.drawRectangle(&point2, 200, 200, Color::Green);
        //pr.drawLine(&point, &point2, Color::Blue);
       // clearScreen(Color::Red);
        std::vector<Point2D> vector;
        vector.push_back(point);
        vector.push_back(point2);
        vector.push_back(point3);
        vector.push_back(point4);
        ////pr.drawConvexShape(vector,sf::Color::Green);
        ////pr.drawCircle(&point, 120.5, Color::Magenta);
        ////test.draw(1, &pr, Color::White);
        pr.drawCircleByAlgorithm(&point, 70 ,Color::Red);
        pr.drawElipseByAlgorithm(&point, 100,50 ,Color::Cyan);
        pr.drawBrokenLine(vector, Color::White,true);
        pr.drawLineByAlgorithm(&point, &point3, Color::Green);
        //pr.floodFill(&pointFill, Color::Magenta, Color::Black);
        //pr.boundryFill(&pointFillBoundry, Color::Magenta, Color::White);;
        //window.draw(shape);
        window->display();
    }
    closeGame();
}
RenderWindow* Engine::getWindow(){
    return window;
}