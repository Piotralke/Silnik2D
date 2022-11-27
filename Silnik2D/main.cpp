#include "Engine.h"


int main()
{
    String title = "Silnik2D";
    RenderWindow window(VideoMode::getDesktopMode(),"Demo");
    Engine* engine = Engine::getInstance(&window);
    
    //engine->changeResolution(1000, 1000);
    engine->gameLoop();
    
    return 0;
}