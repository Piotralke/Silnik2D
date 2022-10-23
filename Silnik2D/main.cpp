#include "Engine.h"


int main()
{
    String title = "Silnik2D";
    RenderWindow window(VideoMode(100,100),"DUPA");
    Engine engine = Engine();
    engine.changeGraphicMode(window,200, 200, title, Style::Fullscreen);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        engine.clearScreen(window,Color::Cyan);

        //window.clear();
        //window.draw(shape);
        window.display();
    }

    

    return 0;
}