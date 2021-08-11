#include "../manager/Window.h"
#include "../graphics/Shader.h"
#include "../scene/Cubes.h"

int main(int argc, char *argv[])
{
    Scene::Cubes *cubes;
    
    Manager::Window *window = new Manager::Window();
    if (window->isReady())
    {
        cubes = new Scene::Cubes(30);
        window->setScene(cubes);
        window->loop();
        delete cubes;
    }
    delete window;    
    
    return 0;
}