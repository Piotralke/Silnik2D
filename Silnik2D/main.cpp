#include "Engine.h"


int main()
{
    String title = "Silnik2D";
    RenderWindow window(VideoMode(1280,720),"DUPA");
    Engine* engine = Engine::getInstance(&window);
    
    //engine->changeResolution(1000, 1000);
    engine->gameLoop();
    
    return 0;
}