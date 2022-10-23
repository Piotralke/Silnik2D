#include "Engine.h"


int main()
{
    String title = "Silnik2D";
    RenderWindow window(VideoMode(100,100),"DUPA");
    Engine engine = Engine(&window);
    engine.changeGraphicMode(200, 200, title, Style::Default);
    engine.gameLoop();
    
    return 0;
}