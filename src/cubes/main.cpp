#include "../manager/Window.h"
#include "../scene/Cubes.h"

int main(int argc, char *argv[])
{
    Scene::Cubes *cubes;
    Manager::Window *window = Manager::Window::instance();
    if (window->isReady())
    {
        cubes = new Scene::Cubes(window->getUModel(), 30);
        window->setScene(cubes);
        window->loop();
        delete cubes;
    }

    return 0;
}